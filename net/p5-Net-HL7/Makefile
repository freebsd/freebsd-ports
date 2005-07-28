# New ports collection makefile for:	net/p5-Net-HL7
# Date created:				26 Jul 2005
# Whom:					Brent B. Powers <bbp2006@columbia.edu>
#
# $FreeBSD$
#

PORTNAME=	Net-HL7
PORTVERSION=	0.73
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	hl7toolkit
PKGNAMEPREFIX=	p5-

MAINTAINER=	bbp2006@columbia.edu
COMMENT=	Net::HL7 - A simple yet flexible API for non-XML HL7 applications

PORTDOCS=	README

PERL_CONFIGURE=	yes

MAN3=		Net::HL7.3 \
		Net::HL7::Request.3 \
		Net::HL7::Connection.3 \
		Net::HL7::Response.3 \
		Net::HL7::Daemon.3 \
		Net::HL7::Segment.3 \
		Net::HL7::Message.3 \
		Net::HL7::Segments::MSH.3 \
		Net::HL7::Messages::ACK.3

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 500000)
IGNORE=	Doesn't build on 4.x
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
