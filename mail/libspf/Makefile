# New ports collection makefile for:	libspf
# Date created:		28 February 2004
# Whom:			Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	libspf
DISTVERSION=	1.0.0-p5
CATEGORIES=	mail
MASTER_SITES=	http://www.libspf.org/files/src/

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	Sender Policy Framework (SPF) library and client

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes

INSTALLS_SHLIB=	yes

PORTDOCS=	*

OPTIONS=	RFC_RECURSION	"Change SPF recursion to 20 (as per RFC)"	off \
		LOGFILE_STATS	"Enables logfile stats"				off \
		DEBUG		"Enables debug option"				off

.include <bsd.port.pre.mk>

.if defined(WITH_RFC_RECURSION)
CONFIGURE_ARGS+=	--enable-rfc-recursion
.endif

.if defined(WITH_LOGFILE_STATS)
CONFIGURE_ARGS+=	--enable-logfile-stats
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|CFLAGS =|CFLAGS +=|" \
		${WRKSRC}/src/libspf/Makefile.in ${WRKSRC}/src/spfqtool/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${FIND} ${WRKSRC}/docs -type d -name CVS | ${XARGS} ${RM} -rf
.for i in docs docs/API docs/API/doxygen docs/API/doxygen/html docs/RFC docs/qmail \
	docs/qmail/1.03 docs/qmail/1.04 docs/qmail/1.05 docs/spfqtool docs/Postfix \
	docs/Postfix/2.1.x docs/Sendmail docs/Sendmail/8.12.x docs/Sendmail/8.13.x \
	docs/Courier-MTA docs/history
	@${MKDIR} ${DOCSDIR}/${i}
	@for f in `${FIND} ${WRKSRC}/${i} ! -type d -maxdepth 1`; do \
		${INSTALL_DATA} $${f} ${DOCSDIR}/${i}; \
	done
.endfor
.endif
	@${MKDIR} ${EXAMPLESDIR}
	@${FIND} ${WRKSRC}/examples -type d -name CVS | ${XARGS} ${RM} -rf
.for i in examples/qmail examples/qmail/control examples/Sendmail
	@${MKDIR} ${EXAMPLESDIR}/${i}
	@for f in `${FIND} ${WRKSRC}/${i} ! -type d -maxdepth 1`; do \
		${INSTALL_DATA} $${f} ${EXAMPLESDIR}/${i}; \
	done
.endfor
	@${MKDIR} ${DATADIR}
	@${FIND} ${WRKSRC}/patches -type d -name CVS | ${XARGS} ${RM} -rf
.for i in patches patches/qmail patches/qmail/1.03 patches/qmail/1.05 patches/Postfix \
	patches/Postfix/2.1.x patches/Sendmail patches/Sendmail/8.12.x patches/Sendmail/8.13.x \
	patches/Courier-MTA
	@${MKDIR} ${DATADIR}/${i}
	@for f in `${FIND} ${WRKSRC}/${i} ! -type d -maxdepth 1`; do \
		${INSTALL_DATA} $${f} ${DATADIR}/${i}; \
	done
.endfor

.include <bsd.port.post.mk>
