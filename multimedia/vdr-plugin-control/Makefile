# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-control
PORTVERSION=	0.0.2a45
PORTREVISION=	13
CATEGORIES=	multimedia
MASTER_SITES=	http://ricomp.de/vdr/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION:S/a45/a/}${DISTVERSIONSUFFIX}

PATCH_SITES=	http://ppa.launchpad.net/the-vdr-team/unstable-plugins/ubuntu/pool/main/v/vdr-plugin-control/ \
		${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	nox/
PATCHFILES=	${PORTNAME}_${PORTVERSION:S/a45/a-45/}yavdr1.diff.gz

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - telnet control plugin

USES=		tar:tgz
PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
WRKSRC=		${WRKDIR}/${PLUGIN}-${DISTVERSION:S/a45/a/}

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin
	${RM} ${WRKSRC}/vdr-plugin-${PLUGIN}-${DISTVERSION:S/a45/a/}/debian/patches/90*
	for i in ${WRKSRC}/vdr-plugin-${PLUGIN}-${DISTVERSION:S/a45/a/}/debian/patches/*.dpatch; do \
		${PATCH} -d ${WRKSRC} `${SED} -n '/^#PATCHOPTIONS:/{s///;p;q;}' $$i` --forward --quiet <$$i ;\
	done

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
