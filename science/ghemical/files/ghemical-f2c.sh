#
# Make new c sources from fortran sources, restore changes,
# made by Tommi Hassinen (3 comments are corrected additionally).
# Should be started in miniMOPAC directory.

f2c fortran/*.f
cp fortran/*.c ./
sed -e 's,/\* fortran/\(.*\)\.f -- translated by f2c (version 20000817),/\* \1.f -- translated by f2c (version 19991025),' \
-e 's,dscal_,mMdscal_,g' \
-e 's,dswap_,mMdswap_,g' \
-e 's,daxpy_,mMdaxpy_,g' \
-i '' *.c 
mv etime.c etime.c.orig
head -18 etime.c.orig > etime.c
echo '#include <time.h>' >> etime.c
tail +19 etime.c.orig >> etime.c
