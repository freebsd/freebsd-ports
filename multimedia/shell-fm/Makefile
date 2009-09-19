# New ports collection makefile for: shell-fm
# Date created:	15 December 2006
# Whom:		Nikos Ntarmos <ntarmos@ceid.upatras.gr>
#
# $FreeBSD$
#

PORTNAME=	shell-fm
PORTVERSION=	0.7
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://nex.scrapping.cc/shell-fm/releases/

MAINTAINER=	ntarmos@cs.uoi.gr
COMMENT=	A command-line client for Last.FM

LIB_DEPENDS=	ao:${PORTSDIR}/audio/libao \
		mad:${PORTSDIR}/audio/libmad

USE_BZIP2=	true
USE_GMAKE=	true
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

MAN1=		shell-fm.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/shell-fm
PORTDOCS=	AUTHORS RELEASE INSTALL
PORTEXAMPLES=	shell-colors.sh shell-fm-tune.sh \
		unix.pl zcontrol

pre-build:
	@${REINPLACE_CMD} \
		-e 's/^PREFIX.*$$/\PREFIX := $$(LOCALBASE)/g' \
		${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
. for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
. endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${ECHO_MSG} "installing examples to ${EXAMPLESDIR}"
. for example in ${PORTEXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/scripts/${example} ${EXAMPLESDIR}
. endfor
.endif

.include <bsd.port.mk>
