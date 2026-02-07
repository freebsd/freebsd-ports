--- src/padic.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/padic.cpp
@@ -406,14 +406,14 @@ void pAdicBuchberger(PolynomialSet &g, int prime, Inte
   for(PolynomialSet::const_iterator i=g.begin();i!=g.end();i++)
     for(PolynomialSet::const_iterator j=g.begin();j!=i;j++)
       {
-log2        debug<<"checking s poly\n"<<*i<<"("<<ST(*i,prime,omega,tieBreaker)<<")"<<"\n"<<*j<<"("<<ST(*j,prime,omega,tieBreaker)<<")"<<"\n";
+gfan_log2        debug<<"checking s poly\n"<<*i<<"("<<ST(*i,prime,omega,tieBreaker)<<")"<<"\n"<<*j<<"("<<ST(*j,prime,omega,tieBreaker)<<")"<<"\n";
         Polynomial f=SPolynomial(*i,*j,prime,omega,tieBreaker);
 //        debug<<"S="<<f<<"\n";
 // Enable the relatively prime criterion by uncommenting this following:
 #if 1
         if(relativelyPrime(ST(*i,prime,omega,tieBreaker).m.exponent,ST(*j,prime,omega,tieBreaker).m.exponent))
           {
-log2            debug<<"SKIPPING\n";
+gfan_log2            debug<<"SKIPPING\n";
           }
         else
 #endif
@@ -424,7 +424,7 @@ log2            debug<<"SKIPPING\n";
         f=longDivision(f,g,prime,omega,tieBreaker,H,u);
         if(!f.isZero())
           {
-log2            debug<<"Adding:"<<f<<"\n";
+gfan_log2            debug<<"Adding:"<<f<<"\n";
             g.push_back(f);
           }
         }
