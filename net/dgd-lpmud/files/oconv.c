/* convert old LPmud .o files to new DGD .o format */
/* $FreeBSD$ */
# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int array, arrbuf[1000];
char buffer[60000];	/* large enough? */

void match(a, b)
char a, b;
{
    if (a != b) {
	fprintf(stderr, "'%c' expected\n", b);
	exit(2);
    }
}

char *scan(buf)
char *buf;
{
    int i;

    switch (*buf++) {
    case '-':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
	while (isdigit(*buf)) buf++;
	break;

    case '"':
	while (*buf != '"') {
	    if (*buf == '\\') buf++;
	    buf++;
	}
	buf++;
	break;

    case '(':
	switch (*buf++) {
	case '{':
	    i = array++;
	    while (*buf != '}') {
		buf = scan(buf);
		match(*buf++, ',');
		arrbuf[i]++;
	    }
	    break;

	case '[':
	    i = array++;
	    while (*buf != ']') {
		buf = scan(buf);
		match(*buf++, ':');
		buf = scan(buf);
		match(*buf++, ',');
		arrbuf[i]++;
	    }
	    break;

	default:
	    fprintf(stderr, "unexpected character '%c'\n", buf[-1]);
	    exit(2);
	}
	buf++;
	match(*buf++, ')');
	break;

    default:
	fprintf(stderr, "unexpected character '%c'\n", buf[-1]);
	exit(2);
    }

    return buf;
}

char *copy(buf)
char *buf;
{
    putchar(*buf);
    switch (*buf++) {
    case '-':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
	while (isdigit(*buf)) putchar(*buf++);
	break;

    case '"':
	while (*buf != '"') {
	    if (*buf == '\r') {
		putchar('\\');
		*buf = 'n';
	    } else if (*buf == '\\') putchar(*buf++);
	    putchar(*buf++);
	}
	putchar(*buf++);
	break;

    case '(':
	putchar(*buf);
	switch (*buf++) {
	case '{':
	    printf("%d|", arrbuf[array++]);
	    while (*buf != '}') {
		buf = copy(buf);
		putchar(*buf++);
	    }
	    break;

	case '[':
	    printf("%d|", arrbuf[array++]);
	    while (*buf != ']') {
		buf = copy(buf);
		putchar(*buf++);
		buf = copy(buf);
		putchar(*buf++);
	    }
	    break;
	}
	putchar(*buf++);
	putchar(*buf++);
	break;
    }

    return buf;
}

main()
{
    char *p;

    puts("#");
    while (fgets(buffer, sizeof(buffer), stdin) != (char *) NULL) {
	p = strchr(buffer, ' ');
	if (p == (char *) NULL) {
	    fprintf(stderr, "variable name expected\n");
	    return 2;
	}
	*p++ = '\0';
	memset(arrbuf, '\0', sizeof(arrbuf));
	array = 0;
	match(*scan(p), '\0');
	printf("%s ", buffer);
	array = 0;
	copy(p);
	putchar('\n');
    }
}
