# New ports collection makefile for:	putty
# Date created:		13 Feb 2004
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	putty
PORTVERSION=	0.58
CATEGORIES=	security ipv6
MASTER_SITES=	http://the.earth.li/~sgtatham/putty/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Secure shell and telnet client

USE_GMAKE=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/unix
MAKEFILE=	Makefile.gtk
CFLAGS+=	-DBSD_PTYS -DOMIT_UTMP

.ifndef WITHOUT_IPV6
CFLAGS+=	-DIPV6
.endif

PLIST_FILES=	bin/plink bin/pscp bin/psftp
MAN1=		plink.1 pscp.1 psftp.1

.ifndef WITHOUT_GTK
USE_GNOME=	gtk12
PLIST_FILES+=	bin/pterm bin/putty bin/puttygen bin/puttytel
MAN1+=		pterm.1 putty.1 puttygen.1 puttytel.1
MAKE_ENV+=	PUTTY_WITH_GTK=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,gtk-config,${GTK_CONFIG},; \
			      s,prefix=/usr/local,prefix=${PREFIX},' \
			     ${WRKSRC}/${MAKEFILE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
CFLAGS+=	-DFREEBSD_MB_SUPPORT

do-configure:
	${CP} ${FILESDIR}/wcrtomb.c ${FILESDIR}/mbrtowc.c \
		${WRKSRC}/
.endif

.include <bsd.port.post.mk>
