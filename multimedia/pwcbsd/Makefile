PORTNAME=	pwcbsd
PORTVERSION=	1.4.1
PORTREVISION=	15
CATEGORIES=	multimedia sysutils
MASTER_SITES=	http://raaf.atspace.org/ \
		http://www.bsd-geek.de/FreeBSD/distfiles/ \
		LOCAL/miwi

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Linux pwc webcam driver ported to FreeBSD
WWW=		http://raaf.atspace.org/

LICENSE=	GPLv2

USES=		kmod uidfix

WRKSRC=		${WRKDIR}/${PORTNAME}

MAKEFILE=	Makefile.kld

PLIST_FILES=	${KMODDIR}/pwc.ko \
		share/man/man4/pwc.4.gz
post-install:
	${INSTALL_MAN} ${WRKSRC}/pwc.4 ${STAGEDIR}${PREFIX}/share/man/man4

.include <bsd.port.mk>
