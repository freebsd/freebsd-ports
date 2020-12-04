--- src/tropicalcurve.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/tropicalcurve.cpp
@@ -48,7 +48,7 @@ IntegerVectorList tropicalCurve(PolynomialSet const &I
 	int stat_isInTropicalVariety=0;
 	int stat_finiteLiftEasy=0;
 	int stat_finiteLiftHard=0;
-	log2 debug<<"tropicalCurve on:"<<I.getRing()<<I<<"\n";
+	gfan_log2 debug<<"tropicalCurve on:"<<I.getRing()<<I<<"\n";
 
 
 
@@ -76,8 +76,8 @@ IntegerVectorList tropicalCurve(PolynomialSet const &I
 //#if 0
 //	for(i=0;i<n;i++)
 	{
-		log2 debug<<"Doing elimination\n";
-		log2 debug<<I<<"\n";
+		gfan_log2 debug<<"Doing elimination\n";
+		gfan_log2 debug<<I<<"\n";
 		list<int> chosenVariables;
 		for(int j=0;j<n;j++)if(j!=i)chosenVariables.push_back(j);
 
@@ -105,7 +105,7 @@ IntegerVectorList tropicalCurve(PolynomialSet const &I
 #endif
 
 
-		log2 debug<<"Done doing elimination\n";
+		gfan_log2 debug<<"Done doing elimination\n";
 //		break;
 		/*
 		 * At this point we need to be careful with whether we are projecting in the torus or in affine space
@@ -148,14 +148,14 @@ IntegerVectorList tropicalCurve(PolynomialSet const &I
 	for(int s=-1;s<=1;s+=2)
 	{
 		IntegerVector v=s*IntegerVector::standardVector(n,i);
-		log2 debug<<"Tropical variety membership test of ray:"<<v<<"\n";
+		gfan_log2 debug<<"Tropical variety membership test of ray:"<<v<<"\n";
 		stat_isInTropicalVariety++;
 		if(isInTropicalVariety(I,v,false))
 		{
 			ret.push_back(s*IntegerVector::standardVector(n,i));
 			if(earlyExit)return ret;
 		}
-		log2 debug<<"Done membership test.\n";
+		gfan_log2 debug<<"Done membership test.\n";
 	}
 
 	IntegerVectorList lowerDimList=tropicalCurve(J2,earlyExit);
@@ -175,7 +175,7 @@ IntegerVectorList tropicalCurve(PolynomialSet const &I
 
 	for(IntegerVectorList::const_iterator k=lowerDimList.begin();k!=lowerDimList.end();k++)
 	{
-		log2 debug<<"Doing polyhedral computations1\n";
+		gfan_log2 debug<<"Doing polyhedral computations1\n";
 #if 1
 		IntegerVectorList generators;generators.push_back((concatenation(IntegerVector(1),*k)));
 		IntegerVectorList lin;lin.push_back((IntegerVector::standardVector(n,i)));
@@ -267,9 +267,9 @@ IntegerVectorList tropicalCurve(PolynomialSet const &I
 			}
 		}*/
 
-		log2 debug<<"Done with polyhedral computations\n";
+		gfan_log2 debug<<"Done with polyhedral computations\n";
 
-		log2 debug<<"Intersection fan dim "<<fanDim<<"\n";
+		gfan_log2 debug<<"Intersection fan dim "<<fanDim<<"\n";
 
 		assert(fanDim!=0);
 		if(fanDim==1)
@@ -281,7 +281,7 @@ IntegerVectorList tropicalCurve(PolynomialSet const &I
 				if(!j->subvector(1,n).isZero())
 					candidates.push_back(*j);
 
-			log2 debug<<"Number of candidates "<<(int)candidates.size()<<"\n";
+			gfan_log2 debug<<"Number of candidates "<<(int)candidates.size()<<"\n";
 
 			if(candidates.size()==1)
 			{
@@ -303,8 +303,8 @@ IntegerVectorList tropicalCurve(PolynomialSet const &I
 
 
 
-	log2 debug<<"Checking complicated list:\n";
-	log2 debug<<complicatedList<<"\n";
+	gfan_log2 debug<<"Checking complicated list:\n";
+	gfan_log2 debug<<complicatedList<<"\n";
 
 	PolynomialSet additionalPolys=I.getRing();
 
@@ -314,7 +314,7 @@ IntegerVectorList tropicalCurve(PolynomialSet const &I
 		for(IntegerVectorList::const_iterator k=complicatedList.begin();k!=complicatedList.end();k++)
 			supportSum+=k->supportAsZeroOneVector();
 
-		log2 debug<<"Support sum:"<<supportSum<<"\n";
+		gfan_log2 debug<<"Support sum:"<<supportSum<<"\n";
 		int j=supportSum.argMax();
 
 
@@ -341,18 +341,18 @@ IntegerVectorList tropicalCurve(PolynomialSet const &I
 
 		PolynomialRing newRing3=I.getRing().withVariablesAppended("H");
 		PolynomialSet J=I.homogenization(newRing3);
-		log2 debug<<"Doing elimination\n";
+		gfan_log2 debug<<"Doing elimination\n";
 		buchberger(&J,T,true);
 		J.changeNumberOfVariables(I.getRing());
 		PolynomialRing newRing2(newRing.getField(),2);
 		PolynomialSet P=J.polynomialRingIntersection(newRing2,&chosenVariables);
 #endif
 		additionalPolys.splice(additionalPolys.end(),J);
-		log2 debug<<"Done eliminating\n";
-		log2 debug<<P<<"\n";
+		gfan_log2 debug<<"Done eliminating\n";
+		gfan_log2 debug<<P<<"\n";
 		assert(P.size()==1);
 
-		log2 debug<<"Doing polyhedral computation\n";
+		gfan_log2 debug<<"Doing polyhedral computation\n";
 		//		debug<<"PFRONT:"<<P.front()<<P.front().exponents()<<"\n";
 				//		PolyhedralFan FF=PolyhedralFan::normalFanOfNewtonPolytope(P.front());
 		PolyhedralFan FF=PolyhedralFan::bergmanOfPrincipalIdeal(P.front());
@@ -372,14 +372,14 @@ IntegerVectorList tropicalCurve(PolynomialSet const &I
 			F=FF.getRays();
 		}
 
-		log2 debug<<"Potential lifts"<<F<<"\n";
+		gfan_log2 debug<<"Potential lifts"<<F<<"\n";
 
 
 		for(IntegerVectorList::iterator k=complicatedList.begin();k!=complicatedList.end();)
 			if((*k)[j]!=0)
 		{
 	//		debug<<I.getRing()<<"\n"<<I;
-			log2 debug<<"Checking:"<<*k<<" with chosen coordinate:"<<j<<"\n";
+			gfan_log2 debug<<"Checking:"<<*k<<" with chosen coordinate:"<<j<<"\n";
 			assert(j!=n);
 
 			IntegerVectorList preCheck;
@@ -396,7 +396,7 @@ IntegerVectorList tropicalCurve(PolynomialSet const &I
 					IntegerVector v=s1*concatenation(concatenation(k->subvector(0,i),IntegerVector(1)),k->subvector(i,n-1))+s2*(*l)[0]*IntegerVector::standardVector(n,i);
 					preCheck.push_back(v);
 				}
-			log2 debug<<"Combined:\n"<<preCheck<<"\n";
+			gfan_log2 debug<<"Combined:\n"<<preCheck<<"\n";
 
 			IntegerVectorList preCheck2;
 			for(IntegerVectorList::const_iterator i=preCheck.begin();i!=preCheck.end();i++)
@@ -406,7 +406,7 @@ IntegerVectorList tropicalCurve(PolynomialSet const &I
 					preCheck2.push_back(*i);
 			}
 
-			log2 debug<<"Combined2:\n"<<preCheck2<<"\n";
+			gfan_log2 debug<<"Combined2:\n"<<preCheck2<<"\n";
 			if(preCheck2.size()==1)
 				ret.splice(ret.end(),preCheck2);
 			else
@@ -503,7 +503,7 @@ IntegerVectorList tropicalCurve(PolynomialSet const &I
 #endif
 
 
-	log2 debug<<"OldtoCheck:"<<toCheck;
+	gfan_log2 debug<<"OldtoCheck:"<<toCheck;
 	{
 		IntegerVectorList toCheck2;
 		for(IntegerVectorList::const_iterator i=toCheck.begin();i!=toCheck.end();i++)
@@ -516,10 +516,10 @@ IntegerVectorList tropicalCurve(PolynomialSet const &I
 	}
 
 
-	log2 debug<<"Checking to check list\n";
+	gfan_log2 debug<<"Checking to check list\n";
 
-	log2 debug<<"Already produced:"<<ret;
-	log2 debug<<"toCheck:"<<toCheck;
+	gfan_log2 debug<<"Already produced:"<<ret;
+	gfan_log2 debug<<"toCheck:"<<toCheck;
 
 	for(IntegerVectorList::const_iterator i=toCheck.begin();i!=toCheck.end();i++)
 	{
@@ -542,7 +542,7 @@ IntegerVectorList tropicalCurve(PolynomialSet const &I
 		debug<<"*k"<<*k<<"\n";
 		//FF.printWithIndices(&debug);
 */
-	log2
+	gfan_log2
 	{
 		debug<<"At dimension "<<n<<"\n";
 		debug<<"To Check\n"<<toCheck;
