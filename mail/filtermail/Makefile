# $FreeBSD$

PORTNAME=	filtermail
PORTVERSION=	0.8.3
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://sourceforge.net/projects/mailfilter/files/Mailfilter/
DISTNAME=	mailfilter-${PORTVERSION}

MAINTAINER=	jmc-filtermail@milibyte.co.uk
COMMENT=	Filter mail on a POP3 server: saves downloading spam

LICENSE=	GPLv3

# This port is filtermail, but the author called it mailfilter. To avoid a
#  clash with another port called mailfilter, we change all files
#  installed by this port from the form *mailfilter* to the form
#  *filtermail*, and similarly the names in the man pages.
#
EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	| ${SED} 's/[mM][aA][iI][lL][fF][iI][lL][tT][eE][rR]/filtermail/g' | ${TAR} -xf -

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		bison gmake
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz \
		man/man5/${PORTNAME}ex.5.gz \
		man/man5/${PORTNAME}rc.5.gz

post-patch:
	@${REINPLACE_CMD} -e 's|filtermail.sourceforge|mailfilter.sourceforge|g' ${WRKSRC}/README

post-extract:
	@${RM} ${WRKSRC}/src/getopt.h

.include <bsd.port.mk>
