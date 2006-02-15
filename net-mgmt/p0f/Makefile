# New ports collection makefile for:	p0f
# Date created:				2000-06-12
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	p0f
PORTVERSION=	2.0.5
CATEGORIES=	net-mgmt
MASTER_SITES=	http://lcamtuf.coredump.cx/p0f/
EXTRACT_SUFX=	.tgz

MAINTAINER=	babak@farrokhi.net
COMMENT=	Passive OS fingerprinting tool

ALL_TARGET=	all p0fq tools
PORTDOCS=	COPYING CREDITS ChangeLog KNOWN_BUGS README TODO win-memleak.txt
MAN1=		p0f.1
WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -E '/^(CC|CFLAGS)/d' ${WRKSRC}/mk/FreeBSD
.for f in config.h doc/README
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/${f}
.endfor

do-install:
.for ii in p0f test/p0fq test/sendack test/sendack2 test/sendsyn
	${INSTALL_PROGRAM} ${WRKSRC}/${ii} ${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/p0frep ${PREFIX}/bin
	${MKDIR} ${PREFIX}/etc/p0f
.for ii in . a. r.
	${INSTALL_DATA} ${WRKSRC}/p0f${ii}fp ${PREFIX}/etc/p0f
.endfor
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
