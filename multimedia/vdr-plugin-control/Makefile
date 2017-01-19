# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-control
PORTVERSION=	0.0.2a45
PORTREVISION=	13
CATEGORIES=	multimedia
MASTER_SITES=	http://ricomp.de/vdr/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION:S/a45/a/}${DISTVERSIONSUFFIX}

PATCH_SITES=	http://ppa.launchpad.net/the-vdr-team/unstable-plugins/ubuntu/pool/main/v/vdr-plugin-control/ \
		LOCAL/nox
PATCHFILES=	${PORTNAME}_${PORTVERSION:S/a45/a-45/}yavdr1.diff.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - telnet control plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:tgz
PATCH_STRIP=	-p1
WRKSRC=		${WRKDIR}/${PLUGIN}-${DISTVERSION:S/a45/a/}

PORTDOCS=	README HISTORY

OPTIONS_DEFINE=	DOCS

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin
	@${RM} ${WRKSRC}/vdr-plugin-${PLUGIN}-${DISTVERSION:S/a45/a/}/debian/patches/90*
	@for i in ${WRKSRC}/vdr-plugin-${PLUGIN}-${DISTVERSION:S/a45/a/}/debian/patches/*.dpatch; do \
		${PATCH} -d ${WRKSRC} `${SED} -n '/^#PATCHOPTIONS:/{s///;p;q;}' $$i` --forward --quiet <$$i ;\
	done

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
