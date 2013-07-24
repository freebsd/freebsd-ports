# Created by: voisine
# $FreeBSD$

PORTNAME=	firefox
PORTVERSION=	22.0
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${PORTVERSION}/linux-i686/en-US

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

EXTRACT_DEPENDS=${NONEXISTENT}:${PORTSDIR}/www/linux-seamonkey:extract

CONFLICTS=	linux-firefox-24.* linux-firefox-1[07].*
USE_LDCONFIG=	yes
USE_BZIP2=	yes

USE_LINUX_APPS=	dbusglib dbuslibs alsalib alsa-plugins-oss

APP_SUBDIR=	browser/ # plugins, extensions

.include "${.CURDIR}/../linux-seamonkey/Makefile.common"

# XXX remove after linux_base-c6 and linux-c6-gtk2 become default
# using seamonkey gre for linux_base-f10 compat
post-extract:	replace-gre
replace-gre:	version-compat-check
	@${ECHO_MSG} "===>   GRE versions are compatible, replacing with" \
		"$$(${MAKE} -V PKGNAME -C ${PORTSDIR}/www/linux-seamonkey)"
	cd $$(${MAKE} -V WRKSRC -C ${PORTSDIR}/www/linux-seamonkey); \
		${CP} lib* dependentlibs.list ${WRKSRC}

version-compat-check:
	@${ECHO_MSG} "===>  Checking GRE version is compatible with" \
		"$$(${MAKE} -V PKGNAME -C ${PORTSDIR}/www/linux-seamonkey)"
	@ff_gre_version=$$(${AWK} -F= '/Milestone/ { print $$2 }' ${WRKSRC}/platform.ini); \
	sm_gre_version=$$(${AWK} -F= '/Milestone/ { print $$2 }' $$(${MAKE} -V WRKSRC -C ${PORTSDIR}/www/linux-seamonkey)/platform.ini); \
	if [ $$ff_gre_version != $$sm_gre_version ]; then \
	    ${ECHO_MSG} "===>   GRE versions aren't compatible, aborting"; \
	    exit 1; \
	fi

.include <bsd.port.mk>
