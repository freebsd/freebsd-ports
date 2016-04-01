# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	esmtp
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Relay-only Mail Transfer Agent with sendmail compatible syntax

LICENSE=	GPLv2

LIB_DEPENDS=	libesmtp.so:mail/libesmtp

USES=		tar:bzip2 bison
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

PORTDOCS=	README
PLIST_FILES=	bin/esmtp etc/esmtprc.sample man/man1/esmtp.1.gz \
		man/man5/esmtprc.5.gz

SUB_FILES=	pkg-message

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

post-patch:
.for file in ${PORTNAME}.1
	@${REINPLACE_CMD} -e \
		's|^/etc|${PREFIX}/etc|g' ${WRKSRC}/${file}
.endfor
.for file in esmtprc.5 sample.esmtprc
	@${REINPLACE_CMD} -e \
		's|/usr/bin/|${LOCALBASE}/bin/|g ; \
		 s|/usr/lib/|/usr/libexec/|g' ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/esmtprc.5 ${STAGEDIR}${MAN5PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/sample.esmtprc \
		${STAGEDIR}${PREFIX}/etc/esmtprc.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
