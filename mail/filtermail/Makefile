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
PORTVERSION=	0.8.2
CATEGORIES=	mail
MASTER_SITES=	SFP \
		http://home.in.tum.de/baueran/%SUBDIR%/
MASTER_SITE_SUBDIR=	mailfilter/Mailfilter/${PORTVERSION}
DISTNAME=	mailfilter-${PORTVERSION}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Filter mail on a POP3 server: saves downloading spam

LICENSE=	GPLv3

# This port is filtermail, but the author called it mailfilter. To avoid a
#  clash with another port called mailfilter, we change all files
#  installed by this port from the form *mailfilter* to the form
#  *filtermail*, and similarly the names in the man pages.
#
EXTRACT_AFTER_ARGS=	| ${SED} 's/[mM][aA][iI][lL][fF][iI][lL][tT][eE][rR]/filtermail/g' | ${TAR} -xf -

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BISON=	build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		filtermail.1
MAN5=		filtermailex.5 filtermailrc.5

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/filtermail

post-patch:
	@${REINPLACE_CMD} -e 's|filtermail.sourceforge|mailfilter.sourceforge|g' ${WRKSRC}/README

post-extract:
	@${RM} -f ${WRKSRC}/src/getopt.h

.include <bsd.port.mk>
