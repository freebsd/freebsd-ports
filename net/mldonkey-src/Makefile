# New ports collection makefile for:	mldonkey
# Date created:		21 August 2002
# Whom:			Holger Lamm <holger@e-gitt.net>
#
# $FreeBSD$
#

PORTNAME=	mldonkey
PORTVERSION=	2.02.0
CATEGORIES=	net
MASTER_SITES=	http://ernie.eit.uni-kl.de/mldonkey/ \
		http://savannah.nongnu.org/download/mldonkey/stable/contributed/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.0$/-0/}.shared.${ARCH}-${OPSYS}

MAINTAINER=	holger@e-gitt.net

LIB_DEPENDS=	c.4:${PORTSDIR}/misc/compat4x

ONLY_FOR_ARCHS=	alpha i386
USE_BZIP2=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-distrib-${PORTVERSION}

DIRNAME=	${HOME}/.mldonkey

DOCFILES=	AUTHORS BUGS ChangeLog Developers.txt FAQ.html \
		Readme.txt TODO ed2k_links.txt

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" ${FILESDIR}/wrapper.sh > \
		${WRKDIR}/wrapper.sh

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mldonkey		${PREFIX}/bin/mldonkey-real
	@${INSTALL_SCRIPT} ${WRKDIR}/kill_mldonkey	${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/mldonkey_previewer	${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh		${PREFIX}/bin/mldonkey
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

post-install:
	@${SED} -e 's|/usr/local/|${PREFIX}/|' ${PKGMESSAGE}

.include <bsd.port.mk>
