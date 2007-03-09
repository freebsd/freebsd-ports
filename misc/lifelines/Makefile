# New ports collection makefile for:	lifelines
# Date created:		10 August 2000
# Whom:			Matt Emmerton <matt@gsicomp.on.ca>
#
# $FreeBSD$
#

PORTNAME=	lifelines
PORTVERSION=	3.0.50
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	matt@gsicomp.on.ca
COMMENT=	An advanced genealogical system

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_ICONV=	yes
USE_BZIP2=	yes
USE_BISON=	yes
USE_GETOPT_LONG=yes

MAN1=		btedit.1 dbverify.1 llines.1

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,ncursesw/curses.h,curses.h,' \
		${WRKSRC}/src/hdrs/mycurses.h

post-install:
.if !defined(NOPORTDOCS)
.for file in btedit.1 dbverify.1 llines.1
	${INSTALL_MAN} ${WRKSRC}/docs/${file} ${MANPREFIX}/man/man1
.endfor
.endif

.include <bsd.port.mk>
