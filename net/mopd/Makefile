# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	mopd
PORTVERSION=	2.5.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	LOCAL/cy
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MOP Loader Daemon for netbooting DEC machines

USES=		uidfix
MAKE_ENV=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man/man NO_MANCOMPRESS=true

OPTIONS_DEFINE=	DOCS

DOCS_DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		VAX-netboot-HOWTO VS3100-console-cmds.txt

do-configure:
	@${REINPLACE_CMD} -e 's/MAN=/MAN8=/' ${WRKSRC}/mopd/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/VAX-netboot-HOWTO  \
		${DISTDIR}/VS3100-console-cmds.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
