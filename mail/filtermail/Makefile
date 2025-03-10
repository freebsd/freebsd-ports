PORTNAME=	filtermail
DISTVERSION=	0.8.9
CATEGORIES=	mail
MASTER_SITES=	https://github.com/nondeterministic/mailfilter/releases/download/${PORTVERSION}/
DISTNAME=	mailfilter-${PORTVERSION}

MAINTAINER=	jmc-freebsd2@milibyte.co.uk
COMMENT=	Filter mail on a POP3 server: saves downloading spam
WWW=		https://github.com/nondeterministic/mailfilter/

LICENSE=	GPLv2

USES=		bison gmake localbase:ldflags ssl
GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes

# This port is filtermail, but the author called it mailfilter. To avoid a
#  clash with another port called mailfilter, we change all files
#  installed by this port from the form *mailfilter* to the form
#  *filtermail*, and similarly the names in the man pages.

EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	| ${SED} 's/[mM][aA][iI][lL][fF][iI][lL][tT][eE][rR]/filtermail/g' \
			| ${TAR} -xf -

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
		share/man/man5/${PORTNAME}ex.5.gz \
		share/man/man5/${PORTNAME}rc.5.gz

post-extract:
	@${RM} ${WRKSRC}/src/getopt.h

post-patch:
	@${REINPLACE_CMD} -e 's|filtermail.sourceforge|mailfilter.sourceforge|g' ${WRKSRC}/README

.include <bsd.port.mk>
