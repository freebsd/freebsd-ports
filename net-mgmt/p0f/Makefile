# Created by: trevor
# $FreeBSD$

PORTNAME=	p0f
PORTVERSION=	3.09b
PORTREVISION=	1
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://lcamtuf.coredump.cx/p0f3/releases/ \
		http://fossies.org/unix/privat/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Passive OS fingerprinting tool

LICENSE=	LGPL21

USES=		tar:tgz
USE_RC_SUBR=	p0f

USERS=		p0f
GROUPS=		p0f

PLIST_FILES=	bin/p0f bin/p0f-client bin/p0f-sendsyn \
		bin/p0f-sendsyn6 etc/p0f.fp
PORTDOCS=	ChangeLog README TODO existential-notes.txt \
		extra-sigs.txt

MAKE_ARGS+=	CC="${CC}" CFLAGS="${CFLAGS}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/docs/README
	@${REINPLACE_CMD} -e 's|p0f.fp|${PREFIX}/etc/p0f.fp|g' ${WRKSRC}/config.h

do-install:
.for ii in p0f tools/p0f-client tools/p0f-sendsyn tools/p0f-sendsyn6
	${INSTALL_PROGRAM} ${WRKSRC}/${ii} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/p0f.fp ${STAGEDIR}${PREFIX}/etc/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for ii in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${ii} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
