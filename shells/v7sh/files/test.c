/*
 *      test expression
 *      [ expression ]
 */

#include	"defs.h"
#include <sys/types.h>
#include <sys/stat.h>
#define exp exp_

INT	ap, ac;
STRING	*av;

test(argn, com)
	STRING com[];
	INT argn;
{


        ac = argn; av = com; ap = 1;
        IF eq(com[0],"[")
	THEN	IF !eq(com[--ac], "]")
		THEN	failed("test", "] missing");
		FI
	FI
        com[ac] = 0;
	IF ac <= 1 THEN return(1) FI
        return(exp()?0:1);
}

STRING	nxtarg(mt)	{

	IF ap >= ac
	THEN	IF mt
		THEN	ap++;
                        return(0);
		FI
		failed("test", "argument expected");
	FI
        return(av[ap++]);
}

exp() {
        INT p1;
	STRING	p2;

        p1 = e1();
        p2 = nxtarg(1);
	IF eq(p2, "-o")	THEN return(p1 | exp()) FI
        IF (p2!=0)&&!eq(p2,"]")&&!eq(p2,")")
	THEN	failed("test", synmsg);
	FI
        ap--;
        return(p1);
}

e1() {
        INT p1;

        p1 = e2();
	IF eq(nxtarg(1), "-a") THEN return(p1 & e1()) FI
        ap--;
        return(p1);
}

e2() {
        IF eq(nxtarg(0), "!")
	THEN	return(!e3())
	FI
        ap--;
        return(e3());
}

e3() {
        INT p1;
	REG STRING	a;
	STRING	p2;
	L_INT	atol();
        L_INT int1, int2;

        a=nxtarg(0);
        IF eq(a, "(")
	THEN	p1 = exp();
                IF !eq(nxtarg(0), ")") THEN failed("test",") expected") FI
                return(p1);
	FI

        p2 = nxtarg(1);
        ap--;
        IF !eq(p2,"=")&&!eq(p2,"!=")
	THEN	IF eq(a, "-r") THEN return(tio(nxtarg(0), 4)) FI
		IF eq(a, "-w") THEN return(tio(nxtarg(0), 2)) FI
		IF eq(a, "-x") THEN return(tio(nxtarg(0), 1)) FI
		IF eq(a, "-d") THEN return(ftype(nxtarg(0), S_IFDIR)) FI
		IF eq(a, "-c") THEN return(ftype(nxtarg(0),S_IFCHR)) FI
		IF eq(a, "-b") THEN return(ftype(nxtarg(0), S_IFBLK)) FI
		IF eq(a, "-f") THEN return(ftype(nxtarg(0), S_IFREG)) FI
		IF eq(a, "-u") THEN return(ftype(nxtarg(0), S_ISUID)) FI
		IF eq(a, "-g") THEN return(ftype(nxtarg(0), S_ISGID)) FI
		IF eq(a, "-k") THEN return(ftype(nxtarg(0), S_ISVTX)) FI
		IF eq(a, "-s") THEN return(fsizep(nxtarg(0))) FI
		IF eq(a, "-t")
		THEN	IF ap >= ac	/* no args */
			THEN return(isatty(1));
			ELIF eq((a=nxtarg(0)), "-a")
				ORF eq(a, "-o")
			     THEN	ap--;
					return(isatty(1));
			ELSE return(isatty(atol(a)));
			FI
		FI
		IF eq(a, "-n") THEN return(!eq(nxtarg(0), "")) FI
		IF eq(a, "-z") THEN return(eq(nxtarg(0), "")) FI
	FI

        p2 = nxtarg(1);
	IF p2==0 THEN return(!eq(a, "")) FI
	IF eq(p2, "-a") ORF eq(p2, "-o") 
	THEN	ap--;
		return(!eq(a, ""))
	FI
	IF eq(p2, "=") THEN return(eq(nxtarg(0), a)) FI
	IF eq(p2, "!=") THEN return(!eq(nxtarg(0), a)) FI
        int1 = atol(a);
        int2 = atol(nxtarg(0));
	IF eq(p2, "-eq") THEN return(int1==int2) FI
	IF eq(p2, "-ne") THEN return(int1!=int2) FI
	IF eq(p2, "-gt") THEN return(int1>int2) FI
	IF eq(p2, "-lt") THEN return(int1<int2) FI
	IF eq(p2, "-ge") THEN return(int1>=int2) FI
	IF eq(p2, "-le") THEN return(int1<=int2) FI

	bfailed(btest, badop, p2);
}

tio(a, f)
	STRING	a;
	INT f;
{
	IF access(a, f)==0 
	THEN	return(1);
	ELSE	return(0)
	FI
}

ftype(f,field)
	STRING	f;
	INT field;
{
        struct stat statb;

	IF stat(f,&statb)<0 THEN return(0) FI
	IF (statb.st_mode&field)==field
	THEN	return(1);
	ELSE	return(0)
	FI
}

fsizep(f)
	STRING	f;
{
        struct stat statb;
	IF stat(f, &statb) <0 THEN return(0) FI
        return(statb.st_size>0);
}
