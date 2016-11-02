# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	libspf
DISTVERSION=	1.0.0-p5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.libspf.org/files/src/ \
		LOCAL/mnag/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sender Policy Framework (SPF) library and client

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_JOBS_UNSAFE=yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		autoreconf libtool tar:bzip2
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	RFC_RECURSION LOGFILE_STATS DEBUG DOCS EXAMPLES
RFC_RECURSION_DESC=	Change SPF recursion to 20 (as per RFC)
LOGFILE_STATS_DESC=	Enables logfile stats

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRFC_RECURSION}
CONFIGURE_ARGS+=	--enable-rfc-recursion
.endif

.if ${PORT_OPTIONS:MLOGFILE_STATS}
CONFIGURE_ARGS+=	--enable-logfile-stats
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${FIND} ${WRKSRC}/docs -type d -name CVS | ${XARGS} ${RM} -r
.for i in docs docs/API docs/API/doxygen docs/API/doxygen/html docs/RFC docs/qmail \
	docs/qmail/1.03 docs/qmail/1.04 docs/qmail/1.05 docs/spfqtool docs/Postfix \
	docs/Postfix/2.1.x docs/Sendmail docs/Sendmail/8.12.x docs/Sendmail/8.13.x \
	docs/Courier-MTA docs/history
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${i}
	@for f in `${FIND} ${WRKSRC}/${i} ! -type d -maxdepth 1`; do \
		${INSTALL_DATA} $${f} ${STAGEDIR}${DOCSDIR}/${i}; \
	done
.endfor
.endif
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${FIND} ${WRKSRC}/examples -type d -name CVS | ${XARGS} ${RM} -r
.for i in examples/qmail examples/qmail/control examples/Sendmail
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${i}
	@for f in `${FIND} ${WRKSRC}/${i} ! -type d -maxdepth 1`; do \
		${INSTALL_DATA} $${f} ${STAGEDIR}${EXAMPLESDIR}/${i}; \
	done
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${FIND} ${WRKSRC}/patches -type d -name CVS | ${XARGS} ${RM} -r
.for i in patches patches/qmail patches/qmail/1.03 patches/qmail/1.05 patches/Postfix \
	patches/Postfix/2.1.x patches/Sendmail patches/Sendmail/8.12.x patches/Sendmail/8.13.x \
	patches/Courier-MTA
	@${MKDIR} ${STAGEDIR}${DATADIR}/${i}
	@for f in `${FIND} ${WRKSRC}/${i} ! -type d -maxdepth 1`; do \
		${INSTALL_DATA} $${f} ${STAGEDIR}${DATADIR}/${i}; \
	done
.endfor

.include <bsd.port.mk>
