# New ports collection makefile for: 	filtermail
# Date created:				8 V 2002
# Whom:					Harry Newton
#
# Called this port 'filtermail' because there is already a 'mailfilter'
#  in the ports tree.
#
# $FreeBSD$
#

PORTNAME=	filtermail
PORTVERSION=	0.7.1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://home.in.tum.de/baueran/%SUBDIR%/
MASTER_SITE_SUBDIR=	mailfilter
DISTNAME=	mailfilter-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Filter mail on a pop3 server: saves downloading spam

# This port is filtermail, but the author called it mailfilter. To avoid a
#  clash with another port called mailfilter, we change all files
#  installed by this port from the form *mailfilter* to the form
#  *filtermail*, and similarly the names in the man pages.
#
EXTRACT_AFTER_ARGS=	| ${SED} 's/[mM][aA][iI][lL][fF][iI][lL][tT][eE][rR]/filtermail/g' | ${TAR} -xf -

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GETOPT_LONG=	yes
USE_BISON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		filtermail.1
MAN5=		filtermailex.5 filtermailrc.5

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-extract:
	@${RM} -f ${WRKSRC}/src/getopt.h

.include <bsd.port.mk>
