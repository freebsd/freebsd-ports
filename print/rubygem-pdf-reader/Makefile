# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pdf-reader
PORTVERSION=	1.3.3
CATEGORIES=	print rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A PDF parser conforming as much as possible to the PDF specification

RUN_DEPENDS=	rubygem-afm>=0.2.0:${PORTSDIR}/print/rubygem-afm \
		rubygem-ascii85>=1.0.0:${PORTSDIR}/devel/rubygem-ascii85 \
		rubygem-hashery>=2.0:${PORTSDIR}/devel/rubygem-hashery \
		rubygem-rc4>=0:${PORTSDIR}/security/rubygem-rc4 \
		rubygem-ttfunk>=0:${PORTSDIR}/print/rubygem-ttfunk

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES+=	bin/pdf_callbacks bin/pdf_list_callbacks bin/pdf_object bin/pdf_text

.include <bsd.port.mk>
