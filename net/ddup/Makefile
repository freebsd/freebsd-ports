# New ports collection makefile for:	ddup
# Date created:		30 September 1999
# Whom:			cjm2
#
# $FreeBSD$
#

PORTNAME=	ddup
PORTVERSION=	3.0.1
CATEGORIES=	net
MASTER_SITES=	http://www.ddup.org/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-unix

MAINTAINER=	cjm2@altavista.net

MAN1=		ddup.1
MANCOMPRESSED=	maybe

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

# Uncomment this if you want to enable debugging.
#DEBUG=		-g

MAKE_ARGS=	DEBUG="${DEBUG}"

post-extract:
	cd ${WRKSRC}; ${GUNZIP_CMD} ddup.1.gz

post-patch:
	${PERL} -i -pe 's,!!PREFIX!!,${PREFIX},' ${WRKSRC}/ddupcron.sh
	${PERL} -i -pe 's,/etc\b,${PREFIX}$$&,' ${WRKSRC}/ddup.1

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/
	${ECHO} "#define file_name \"${PREFIX}/etc/ddup.conf\"" > ${WRKSRC}/options.h

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ddupcron.sh ${PREFIX}/sbin/
.if !defined(NOPORTSDOC)
	${MKDIR} ${PREFIX}/share/doc/ddup
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ddup/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
