# New ports collection makefile for:	libocas
# Date created: 	5 Oct 2011
# Whom: 	b.f. <bf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libocas
PORTVERSION=	0.93
CATEGORIES=	math
MASTER_SITES=	http://cmp.felk.cvut.cz/~xfrancv/ocas/ LOCAL/bf
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/.//}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Efficient training of SVM classifiers

LICENSE=	GPLv3

USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_ZIP=	yes

ALL_TARGET=	all linclass
LIBS=		-lm ${PTHREAD_LIBS}
MAKE_ENV=	MEXDETECTED=no

PLIST_FILES=	bin/linclass bin/msvmocas bin/svmocas lib/libocas.so \
		lib/libocas.so.1

.include <bsd.port.pre.mk>

.if ${ARCH} == sparc64
PICFLAG=	-fPIC
.else
PICFLAG=	-fpic
.endif

CFLAGS+=	${PICFLAG} ${PTHREAD_CFLAGS}

post-patch:
	@${REINPLACE_CMD} \
		-e '\|:=|d' \
		-e 's|libocas\.so|&.1|' \
		-e '\|$$(CC) $$(CFLAGS) -o|{s|$$(CFLAGS)|& ${LDFLAGS}|;s|$$| ${LIBS}|;}' \
		${WRKSRC}/Makefile

do-install:
.for p in linclass msvmocas svmocas
	@${INSTALL_PROGRAM} ${WRKSRC}/${p} ${PREFIX}/bin
.endfor
	@${INSTALL_LIB} ${WRKSRC}/libocas.so.1 ${PREFIX}/lib
	@${LN} -sf libocas.so.1 ${PREFIX}/lib/libocas.so

check regression-test test: build
	${WRKSRC}/msvmocas -c 10 -v 1 ${WRKSRC}/data/example4_train.light \
		${WRKSRC}/data/msvmocas.model
	${WRKSRC}/linclass -e -v 1 -o ${WRKSRC}/data/exaple4_test.pred \
		${WRKSRC}/data/example4_test.light ${WRKSRC}/data/msvmocas.model
	${WRKSRC}/svmocas -c 10 -b 1 -v 1 ${WRKSRC}/data/riply_trn.light \
		${WRKSRC}/data/svmocas.model
	${WRKSRC}/linclass -e -v 1 -o ${WRKSRC}/data/riply_tst.pred \
		${WRKSRC}/data/riply_tst.light ${WRKSRC}/data/svmocas.model

.include <bsd.port.post.mk>
