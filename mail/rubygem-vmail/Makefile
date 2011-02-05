# New ports collection makefile for:	Ruby-vmail
# Date created:		2010 12-15
# Whom:			Hsin-Han You <hhyou@cs.nctu.edu.tw>
#
# $FreeBSD$

PORTNAME=	vmail
PORTVERSION=	1.4.6
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	hhyou@cs.nctu.edu.tw
COMMENT=	A Vim interface to Gmail

RUN_DEPENDS=	rubygem-mail>=2.2.12:${PORTSDIR}/mail/rubygem-mail \
		rubygem-highline>=1.6.1:${PORTSDIR}/devel/rubygem-highline

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/vmail bin/vmail_client bin/vmailsend

.include <bsd.port.mk>
