# New ports collection makefile for:	mldonkey
# Date created:		21 August 2002
# Whom:			Holger Lamm <holger@e-gitt.net>
#
# $FreeBSD$
#

PORTNAME=	mldonkey
PORTVERSION=	1.16
CATEGORIES=	net
MASTER_SITES=	http://www.schraegerpunkt.de/ \
		http://ernie.eit.uni-kl.de/mldonkey/
	
DISTNAME=	${PORTNAME}-${PORTVERSION}.static.${ARCH}-FreeBSD

MAINTAINER=	holger@e-gitt.net

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww

ONLY_FOR_ARCHS= i386
USE_BZIP2=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-distrib

DIRNAME=	${HOME}/.mldonkey

# do not strip, it breaks OCAML binaries
STRIP=

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" ${FILESDIR}/wrapper.sh > \
		${WRKDIR}/wrapper.sh
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' \
		${WRKSRC}/kill_mldonkey

pre-install:
# we can strip the GTK binary
	@${STRIP_CMD} ${WRKSRC}/mldonkey_gui

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mldonkey		${PREFIX}/bin/mldonkey-real
	@${INSTALL_PROGRAM} ${WRKSRC}/mldonkey_gui	${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/kill_mldonkey	${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/mldonkey_previewer	${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh		${PREFIX}/bin/mldonkey
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Readme.txt ${DOCSDIR}
.endif

post-install:
	@${SED} -e 's|/usr/local/|${PREFIX}/|' ${PKGMESSAGE}

.include <bsd.port.pre.mk>

install-user: extract
	@${TEST} -d ${DIRNAME} ||	${MKDIR} ${DIRNAME}
	@${CP} ${WRKSRC}/servers.ini	${DIRNAME}/

.include <bsd.port.post.mk>
