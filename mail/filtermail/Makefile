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
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://home.in.tum.de/baueran/%SUBDIR%/
MASTER_SITE_SUBDIR=	mailfilter
DISTNAME=	mailfilter-${PORTVERSION}

MAINTAINER=	harry_newton@telinco.co.uk
COMMENT=	Filter mail on a pop3 server: saves downloading spam

LIB_DEPENDS=	intl:${PORTSDIR}/devel/gettext \
		iconv:${PORTSDIR}/converters/libiconv

GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_GMAKE=	yes

MAN1=		filtermail.1
MAN5=		filtermailrc.5 filtermailex.5

# This port is filtermail, but the author called it mailfilter. To avoid a
#  clash with another port called mailfilter, we change all files
#  installed by this port from the form *mailfilter* to the form
#  *filtermail*, and similarly the names in the man pages.
#
EXTRACT_AFTER_ARGS=	| ${SED} 's/[mM][aA][iI][lL][fF][iI][lL][tT][eE][rR]/filtermail/g' | ${TAR} -xf -
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile (bad C++ code)"
.endif

.include <bsd.port.post.mk>
