# New ports collection makefile for:	lightning
# Date created:		2006-10-13
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/mail/lightning/Makefile,v 1.1 2006/10/14 03:49:20 ahze Exp $

PORTNAME=	lightning
PORTVERSION=	0.7
PORTREVISION=	5
CATEGORIES=	mail deskutils
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	calendar/${PORTNAME}/releases/${DISTVERSION}/source
DISTNAME=	${PORTNAME}-sunbird-${DISTVERSION}-source

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Thunderbird mail client with lightning calendar plugin

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

LATEST_LINK=	thunderbird-${PORTNAME}
CONFLICTS=	thunderbird-[0-9]* lightning-xpi-0.[0-9]*
ALL_TARGET=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
WANT_GNOME=	yes
WANT_PERL=	yes
LIGHTNING_DIR=	lib/thunderbird/extensions/{e2fda1a4-762b-4020-b5ad-a41df1933103}
MOZILLA=	thunderbird
MOZILLA_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/icons/default.xpm
MOZILLA_ICON=		${MOZILLA}.xpm
PKGCONFIG_FILES?=	${MOZILLA}-js \
			${MOZILLA}-xpcom ${MOZILLA}-plugin
MOZ_PKGCONFIG_FILES=	${PKGCONFIG_FILES}
MOZ_OPTIONS=	--enable-application=mail \
		--enable-system-cairo \
		--with-system-nss \
		--enable-canvas \
		--program-transform-name='s/lightning/${MOZILLA}/'
MOZ_EXTENSIONS=	default,lightning
MOZ_MK_OPTIONS=	MOZ_CO_PROJECT=mail,calendar

.include <bsd.port.pre.mk>

GECKO_PTHREAD_LIBS!=${CC} -dumpspecs | ${GREP} -m 1 pthread | ${SED} -e 's|^.*%{\!pg: %{pthread:|| ; s|}.*$$||' || ${TRUE}

.if ${ARCH}=="ia64"
IGNORE=	does not build
.endif

pre-everything::
	@if [ -n "`${PKG_INFO} -xI '^thunderbird-[0-9].[0-9]*'`" ]; then \
		${ECHO_CMD} "${PKGNAME}: thunderbird conflicts with ${PORTNAME}, if you wish to not"; \
		${ECHO_CMD} "deinstall thunderbird you should check out ${PORTSDIR}/deskutils/lightning-xpi"; \
		${FALSE}; \
	fi

post-patch:
	@${SED} -e 's|@MOZILLA_ICON@|${MOZILLA_ICON}|' \
		${FILESDIR}/${MOZILLA}.desktop.in >${WRKDIR}/${MOZILLA}.desktop
	@${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS:C/-pthread/${GECKO_PTHREAD_LIBS}/}|' \
		${WRKSRC}/storage/build/Makefile.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/security/manager/ssl/src/Makefile.in

port-pre-install:
	${MKDIR} ${FAKEDIR}/${LIGHTNING_DIR}
	${UNZIP_CMD} ${WRKSRC}/dist/xpi-stage/lightning.xpi -d ${FAKEDIR}/${LIGHTNING_DIR}

pre-install:
	${ECHO_CMD} 'share/applications/${MOZILLA}.desktop' >> ${PLIST}
	${ECHO_CMD} 'share/pixmaps/${MOZILLA_ICON}' >> ${PLIST}
	${ECHO_CMD} '@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}' >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/share/applications ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA}.desktop ${PREFIX}/share/applications
	${LN} -sf ${MOZILLA_ICON_SRC} ${PREFIX}/share/pixmaps/${MOZILLA_ICON}

.include "${PORTSDIR}/www/mozilla/Makefile.common"
.include <bsd.port.post.mk>
