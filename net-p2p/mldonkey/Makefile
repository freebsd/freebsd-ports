# New ports collection makefile for:	mldonkey
# Date created:		21 August 2002
# Whom:			Holger Lamm <holger@e-gitt.net>
#
# $FreeBSD$
#

PORTNAME=	mldonkey
PORTVERSION=	2.04.r1
CATEGORIES=	net
MASTER_SITES=	http://savannah.nongnu.org/download/mldonkey/release-2.04rc1/contributed/holger/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}-0.shared.${ARCH}-${OPSYS}-hl

MAINTAINER=	holger@e-gitt.net
COMMENT=	A OCAML client for eDonkey and Overnet peer-to-peer networks (core)

ONLY_FOR_ARCHS=	alpha i386
USE_BZIP2=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-distrib-${PORTVERSION:S/.r/rc/}-0

DIRNAME=	${HOME}/.mldonkey

DOCFILES=	AUTHORS BUGS ChangeLog Developers.txt FAQ.html \
		Readme.txt TODO ed2k_links.txt

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" ${FILESDIR}/wrapper.sh > \
		${WRKDIR}/wrapper.sh

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mldonkey		${PREFIX}/bin/mldonkey-real
	@${INSTALL_SCRIPT} ${FILESDIR}/kill_mldonkey	${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh		${PREFIX}/bin/mldonkey
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

post-install:
	@${SED} -e 's|/usr/local/|${PREFIX}/|' ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c_r.4:${PORTSDIR}/misc/compat4x
.endif

.include <bsd.port.post.mk>
