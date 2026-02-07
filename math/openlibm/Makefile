PORTNAME=	openlibm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.7
CATEGORIES=	math

MAINTAINER=	laurent.chardon@gmail.com
COMMENT=	High quality system independent, portable, open source libm
WWW=		https://openlibm.org

LICENSE=		MIT ISCL BSD2CLAUSE LGPL21+ SUNPRO PD
LICENSE_COMB=		multi
LICENSE_NAME_SUNPRO=	SunPro License
LICENSE_FILE_SUNPRO=	${LICENSE_FILE}
LICENSE_FILE=		${WRKSRC}/LICENSE.md
LICENSE_PERMS_SUNPRO=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_armv6=	fails to compile: a parameter list without types is only allowed in a function definition
BROKEN_armv7=	fails to compile: a parameter list without types is only allowed in a function definition

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	JuliaMath

USE_LDCONFIG=	yes

do-test:
	(cd ${WRKSRC}/test && ${SETENVI} ${CC} test-double.c -o test-double \
	    ${CFLAGS} ${CPPFLAGS} -std=c99 ${LDFLAGS} \
	    -I.. -I../include -I../${ARCH} -I../src -DASSEMBLER	\
	    -D__BSD_VISIBLE -fno-builtin -Wno-implicit-function-declaration \
	    -L${BUILD_WRKSRC} -lopenlibm -Wl,-rpath=${BUILD_WRKSRC})
	(cd ${WRKSRC}/test && ${SETENVI} ${CC} test-float.c -o test-float \
	    ${CFLAGS} ${CPPFLAGS} -std=c99 ${LDFLAGS} \
	    -I.. -I../include -I../${ARCH} -I../src -DASSEMBLER	\
	    -D__BSD_VISIBLE -fno-builtin -Wno-implicit-function-declaration \
	    -L${BUILD_WRKSRC} -lopenlibm -Wl,-rpath=${BUILD_WRKSRC})
	(cd ${WRKSRC}/test && ./test-double && ./test-float)

.include <bsd.port.options.mk>

# Arch specific headers
.if ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	X86=""
.else
PLIST_SUB+=	X86="@comment "
.endif
.if ${ARCH} == amd64
PLIST_SUB+=	AMD64=""
.else
PLIST_SUB+=	AMD64="@comment "
.endif
.if ${ARCH} == i386
PLIST_SUB+=	I386=""
.else
PLIST_SUB+=	I386="@comment "
.endif

.include <bsd.port.mk>
