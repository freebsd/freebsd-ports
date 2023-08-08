--- define.f90.orig	2023-05-04 20:39:35 UTC
+++ define.f90
@@ -441,11 +441,11 @@ real*8 :: dp_init1,dp_end1,dp_init2,dp_end2,dp_init3,d
 !!! Other external parameter !!!
 integer :: iautointgrid=1,radpot=75,sphpot=434 !sphpot=230/302/434/590/770, low is 50*434, high is 100*590
 integer :: ispecial=0 !=0: Normal, =1 specific for Chunying Rong, =2 for Shubin's 2nd project
-#ifdef _WIN32
-integer :: isys=1 !Windows
-#else
+!#ifdef _WIN32
+!integer :: isys=1 !Windows
+!#else
 integer :: isys=2 !Linux/MacOS
-#endif
+!#endif
 integer :: igenP=1,iwfntmptype=1,iESPcode=2,outmedinfo=0,iaddprefix=0,intmolcust=0,isilent=0,idelvirorb=1
 integer :: ifchprog=1,iloadascart=0,iloadGaugeom=1,iloadORCAgeom=1,maxloadexc=0,iprintLMOorder=0,iMCBOtype=0,ibasinlocmin=0
 integer :: iuserfunc=0,iDFTxcsel=84,iKEDsel=0,ispheratm=1,ishowchgtrans=0,uESEinp=0,SpherIVgroup=0,MCvolmethod=2,readEDF=1,isupplyEDF=2,ishowptESP=1,imolsurparmode=1,nPGmaxatm=200
@@ -609,4 +609,4 @@ real*8,allocatable :: DMNAO(:,:),DMNAOa(:,:),DMNAOb(:,
 real*8,allocatable :: NAOMO(:,:) !size of (numNAO,NBsUse). (i,r) is coeff. of NAO i in MO r. If numNAO<nbasis, the gap is filled by blank. For open shell, this records alpha part.
 real*8,allocatable :: NAOMOb(:,:) !NAOMO for beta part
 real*8,allocatable :: AONAO(:,:) !size of (nbasis,numNAO)
-end module
\ No newline at end of file
+end module
