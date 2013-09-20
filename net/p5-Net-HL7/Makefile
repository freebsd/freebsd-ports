# Created by: Brent B. Powers <bbp2006@columbia.edu>
# $FreeBSD$

PORTNAME=	Net-HL7
PORTVERSION=	0.75
CATEGORIES=	net perl5
MASTER_SITES=	SF/hl7toolkit/hl7api/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	bbp2006@columbia.edu
COMMENT=	Net::HL7 - A simple yet flexible API for non-XML HL7 applications

PORTDOCS=	README

USES=		perl5
USE_PERL5=	configure

MAN3=		Net::HL7.3 \
		Net::HL7::Request.3 \
		Net::HL7::Connection.3 \
		Net::HL7::Response.3 \
		Net::HL7::Daemon.3 \
		Net::HL7::Segment.3 \
		Net::HL7::Message.3 \
		Net::HL7::Segments::MSH.3 \
		Net::HL7::Messages::ACK.3

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
