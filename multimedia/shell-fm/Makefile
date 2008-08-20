# New ports collection makefile for: shell-fm
# Date created:	15 December 2006
# Whom:		Nikos Ntarmos <ntarmos@ceid.upatras.gr>
#
# $FreeBSD$
#

PORTNAME=	shell-fm
PORTVERSION=	0.4
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://ntarmos.dyndns.org/Software/FreeBSD/

MAINTAINER=	ntarmos@ceid.upatras.gr
COMMENT=	A command-line client for Last.FM

LIB_DEPENDS=	ao:${PORTSDIR}/audio/libao \
		mad:${PORTSDIR}/audio/libmad

USE_AUTOTOOLS=	aclocal:19 automake:19 autoheader:262 autoconf:262
AUTOMAKE_ARGS=	--add-missing --copy
ACLOCAL_ARGS=	-I m4
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} && \
	${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL})

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/AUTHORS ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/COPYING ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${ECHO_MSG} "installing example config file to ${EXAMPLESDIR}"
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_MAN} ${WRKSRC}/shell-fm.rc-example ${EXAMPLESDIR}
.endif

MAN1=		shell-fm.1
MANCOMPRESSED=	no
PLIST_FILES=	bin/shell-fm
PORTDOCS=	AUTHORS COPYING README
PORTEXAMPLES=	shell-fm.rc-example

.include <bsd.port.mk>
