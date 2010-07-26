# New ports collection makefile for:	hyperestraier
# Date created:		2005-09-11
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports-stable/textproc/hyperestraier/Makefile,v 1.3 2006/10/17 11:45:45 ahze Exp $

PORTNAME=	hyperestraier
PORTVERSION=	1.4.13
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A full-text search system

BUILD_DEPENDS=	qdbm>=1.8.77:${PORTSDIR}/databases/qdbm
# check configure for min version of qdbm.
LIB_DEPENDS=	qdbm.14:${PORTSDIR}/databases/qdbm

USE_ICONV=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-bzip2 --disable-zlib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

OPTIONS=	LZO "Enable lzo support" off \
		MECAB "Enable mecab support" off

MAN1=		estcall.1 estcmd.1 estconfig.1 estmaster.1 estwaver.1
MAN3=		estnode.3 estraier.3

.include <bsd.port.pre.mk>

.if defined(WITH_LZO)
CONFIGURE_ARGS+=	--enable-lzo
LIB_DEPENDS+=	lzo2:${PORTSDIR}/archivers/lzo2
.endif

.if defined(WITH_MECAB)
CONFIGURE_ARGS+=	--enable-mecab
LIB_DEPENDS+=	mecab:${PORTSDIR}/japanese/mecab
RUN_DEPENDS+=	${LOCALBASE}/lib/mecab/dic/ipadic/matrix.bin:${PORTSDIR}/japanese/mecab-ipadic
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|@libdir@/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
	${RM} -f ${WRKSRC}/doc/intro-en.html~ ${WRKSRC}/doc/intro-ja.html~

.include <bsd.port.post.mk>
