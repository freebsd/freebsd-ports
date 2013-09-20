# $FreeBSD$

PORTNAME=	smtp
PORTVERSION=	3.3
CATEGORIES=	mail perl5
MASTER_SITES=	http://www.logix.cz/michal/devel/smtp-cli/
PKGNAMESUFFIX=	-cli
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}
EXTRACT_SUFX=	-${PORTVERSION}

MAINTAINER=	fw@moov.de
COMMENT=	Powerful SMTP command line client

RUN_DEPENDS=	p5-Digest-HMAC>0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-File-LibMagic>0:${PORTSDIR}/devel/p5-File-LibMagic \
		p5-IO-Socket-SSL>0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-MIME-Lite>0:${PORTSDIR}/mail/p5-MIME-Lite \
		p5-Term-ReadKey>0:${PORTSDIR}/devel/p5-Term-ReadKey

NO_BUILD=	yes
WRKSRC=		${WRKDIR}

PLIST_FILES=	bin/smtp-cli

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
RUN_DEPENDS+=	p5-IO-Socket-INET6>0:${PORTSDIR}/net/p5-IO-Socket-INET6
# won't be needed if p5-IO-Socket-SSL > 1.74_1
.endif

do-extract:
	@${MKDIR} ${WRKSRC}/
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}/${DISTNAME}

post-patch:
	@${REINPLACE_CMD} -e '1 s|#!/usr/bin/perl|#!${PERL}|' ${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
