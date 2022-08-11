PORTNAME=	sendok
PORTVERSION=	0.9.2
CATEGORIES=	mail
MASTER_SITES=	http://peff.net/sendok/ \
		http://www.cs.virginia.edu/~jrk3g/sendok/

MAINTAINER=	zakj@nox.cx
COMMENT=	Generates qmail email addresses with timed cookies

USES=		qmail:run

PLIST_FILES=	bin/sendok-check bin/sendok-create

ALL_TARGET=	it

post-patch:
	@${ECHO_CMD} ${CC} ${CFLAGS} >${WRKSRC}/conf-cc

do-install:
.for f in sendok-check sendok-create
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
