# New ports collection makefile for:		linux-opera
# Date created:					December 6th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}
CATEGORIES=	www linux
MASTER_SITES=	ftp://ftp.opera.com/pub/opera/linux/${OPERA_VER:S/.//}/final/en/i386/ \
		ftp://ftp.sunet.se/pub/www/clients/Opera/linux/${OPERA_VER:S/.//}/final/en/i386/ \
		ftp://sunsite.cnlab-switch.ch/mirror/opera/linux/${OPERA_VER:S/.//}/final/en/i386/ \
		ftp://ftp.tiscali.nl/pub/mirrors/opera/linux/${OPERA_VER:S/.//}/final/en/i386/ \
		ftp://ftp.ntua.gr/pub/www/Opera/linux/${OPERA_VER:S/.//}/final/en/i386/ \
		http://mirrors.pmmf.hu/mirror/opera/linux/${OPERA_VER:S/.//}/final/en/i386/ \
		ftp://ftp.task.gda.pl/pub/opera/linux/${OPERA_VER:S/.//}/final/en/i386/ \
		ftp://ftp.planetmirror.com/pub/opera/linux/${OPERA_VER:S/.//}/final/en/i386/ \
		http://gd.tuwien.ac.at/infosys/browsers/opera/linux/${OPERA_VER:S/.//}/final/en/i386/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/opera/linux/${OPERA_VER:S/.//}/final/en/i386/&,}
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${OPERA_VER}.gcc4-bundled-qt4.i386

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A blazingly fast, full-featured, standards-compliant browser

WRKSRC=		${WRKDIR}/${DISTNAME:S/.gcc/-${OPERA_BUILD}.gcc/}
USE_BZIP2=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	aspell naslibs png xorglibs
ONLY_FOR_ARCHS=	i386 amd64

NO_BUILD=	yes

OPERA_VER=	10.01
OPERA_BUILD=	4682
DATADIR=	${PREFIX}/share/${UNIQUENAME}
DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}

MAN1=		linux-opera.1

.include <bsd.port.pre.mk>

.if ${OSVERSION}<700055
IGNORE=	you need FreeBSD>=7.0 RELEASE with Linux emulation 2.6.x.
.elif ${OSVERSION}<800076 && ! defined (OVERRIDE_LINUX_NONBASE_PORTS)
IGNORE=	you need to use non-default linux ports (define OVERRIDE_LINUX_BASE_PORT=f8 and OVERRIDE_LINUX_NONBASE_PORTS=f8). You also can use f10 instead of f8, but I only have tested it with f8.
.endif

post-extract:
	@${MV} ${WRKSRC}/usr/share/man/man1/opera.1 \
		${WRKSRC}/usr/share/man/man1/${UNIQUENAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%LINUXBASE%%|${LINUXBASE}|g' \
			${WRKSRC}/install.sh \
			${WRKSRC}/usr/share/opera/defaults/pluginpath.ini
	@${REINPLACE_CMD} -e 's|man1/opera.1|man1/${UNIQUENAME}.1|g' \
		${WRKSRC}/Manifest.md5
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	@(cd ${WRKSRC} && ./install.sh \
			--prefix=${PREFIX} \
			--docdir=${DOCSDIR} \
			--sharedir=${DATADIR} \
			--exec_prefix=${DATADIR}/bin \
			--plugindir=${DATADIR}/plugins)

.include <bsd.port.post.mk>
