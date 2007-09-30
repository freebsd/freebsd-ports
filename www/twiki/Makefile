# Ports collection makefile for:  TWiki
# Date created:			  Fri Mar  7 14:36:05 CST 2003
# Whom:				  Justin Hawkins <justin@hawkins.id.au>
#
# $FreeBSD$
#

PORTNAME=	twiki
PORTVERSION=	4.1.2
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://twiki.org/p/pub/Codev/Release/ \
		${MASTER_SITE_GENTOO}/distfiles/
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	TWiki-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	A flexible, powerful, and easy to use Web-based collaboration platform

RUN_DEPENDS=	${SITE_PERL}/CGI/Session.pm:${PORTSDIR}/www/p5-CGI-Session

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_PERL5=	yes

TWIKI?=		${WWWOWN}/twiki
TWIKIDIR?=	${PREFIX}/${TWIKI}

PLIST_SUB=	TWIKI=${TWIKI}
SUB_LIST=	WWWUSER=${WWWOWN} WWWGROUP=${WWWGRP} TWIKIDIR=${TWIKIDIR} \
		REINPLACE_CMD="${REINPLACE_CMD}"
SUB_FILES=	pkg-install
PKGINSTALL=	${WRKDIR}/pkg-install

pre-everything::
	@${ECHO} "****************************************************************"
	@${ECHO} "*  If you're upgrading, Ctrl-C now and do the upgrade by hand. *"
	@${ECHO} "*  This software can't be upgraded automatically without       *"
	@${ECHO} "*  damaging data in your wiki!                                 *"
	@${ECHO} "****************************************************************"
	@sleep 1

post-patch:
.for F in data/TWiki/TWikiInstallationGuide.txt,v data/TWiki/TWikiDocumentation.txt,v data/TWiki/TWikiInstallationGuide.txt INSTALL.html lib/TWiki.spec twiki_httpd_conf.txt
	@${REINPLACE_CMD} -i "" -e "s|\/home\/httpd\/twiki|${TWIKIDIR}|g" \
		${WRKSRC}/$F
.endfor

do-install:
	${INSTALL} -d -m 0755 ${TWIKIDIR}
	(cd ${WRKSRC} && ${FIND} . -not -name ".PLIST.*" -not -name '.*_done.*' -not -name pkg-install | \
		${CPIO} -pdmu -R${SHAREOWN}:${SHAREGRP} ${TWIKIDIR})

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
