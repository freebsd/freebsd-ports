#! /bin/sh
#
# From
# $NetBSD: regress.sh,v 1.2 2002/12/21 04:06:15 schmonz Exp $

# one can do, for example to test with openssl: 
#  DIGESTDIR=/path/to DIGESTCMD=openssl sh regress.sh
DIGESTDIR=${DIGESTDIR:-.}
DIGESTCMD=${DIGESTCMD:-digest}
DIGEST=${DIGESTDIR}/${DIGESTCMD}

# grabbed from GNU autoconf
case `echo "testing\c"; echo 1,2,3`,`echo -n testing; echo 1,2,3` in
  *c*,-n*) ECHO_N= ECHO_C='
' ;; 
  *c*,*  ) ECHO_N=-n ECHO_C= ;;
  *)      ECHO_N= ECHO_C='\c' ;;
esac


cat > expected1 << EOF
ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad
cb00753f45a35e8bb5a03d699ac65007272c32ab0eded1631a8b605a43ff5bed8086072ba1e7cc2358baeca134c825a7
ddaf35a193617abacc417349ae20413112e6fa4e89a97ea20a9eeee64b55d39a2192992a274fc1a836ba3c23a3feebbd454d4423643ce80e2a9ac94fa54ca49f
EOF
echo $ECHO_N "abc$ECHO_C" | ${DIGEST} sha256 > output1
echo $ECHO_N "abc$ECHO_C" | ${DIGEST} sha384 >> output1
echo $ECHO_N "abc$ECHO_C" | ${DIGEST} sha512 >> output1
diff expected1 output1 || echo "*** WARNING: output differs in test 1 (sha256, sha384, sha512) ***"

rm -f expected1 output1

cat > expected2 << EOF
248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1
3391fdddfc8dc7393707a65b1b4709397cf8b1d162af05abfe8f450de5f36bc6b0455a8520bc4e6f5fe95b1fe3c8452b
204a8fc6dda82f0a0ced7beb8e08a41657c16ef468b228a8279be331a703c33596fd15c13b1b07f9aa1d3bea57789ca031ad85c7a71dd70354ec631238ca3445
EOF
echo $ECHO_N "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq$ECHO_C" | ${DIGEST} sha256 > output2
echo $ECHO_N "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq$ECHO_C" | ${DIGEST} sha384 >> output2
echo $ECHO_N "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq$ECHO_C" | ${DIGEST} sha512 >> output2
diff expected2 output2 || echo "*** WARNING: output differs in test 2 (sha256, sha384, sha512) ***"

rm -f expected2 output2


cat > expected3 << EOF
8215ef0796a20bcaaae116d3876c664a
EOF
echo $ECHO_N "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq$ECHO_C" | ${DIGEST} md5 > output3
diff expected3 output3 || echo "*** WARNING: output differs in test 3 (md5) ***"

rm -f expected3 output3

cat > expected4 << EOF
12a053384a9c0c88e405a06c27dcf49ada62eb2b
EOF
echo $ECHO_N "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq$ECHO_C" | ${DIGEST} rmd160 > output4
diff expected4 output4 || echo "*** WARNING: output differs in test 4 (rmd160) ***"

rm -f expected4 output4

cat > expected5 << EOF
84983e441c3bd26ebaae4aa1f95129e5e54670f1
EOF
echo $ECHO_N "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq$ECHO_C" | ${DIGEST} sha1 > output5
diff expected5 output5 || echo "*** WARNING: output differs in test 5 (sha1) ***"

rm -f expected5 output5



exit 0
