# Created by: wosch
# $FreeBSD$

PORTNAME=	portcheckout
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://wolfram.schneider.org/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Checkout and build ports and all depending ports

USES=		perl5 shebangfix uidfix
SHEBANG_FILES=	${PORTNAME}.pl
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

post-patch:
	${REINPLACE_CMD} -e 's/cvs checkout/& -P/g; \
		s/\(exec\) \(pod2text\)/\1 "\2"/;' \
		${WRKSRC}/${PORTNAME}.pl

.include <bsd.port.mk>
