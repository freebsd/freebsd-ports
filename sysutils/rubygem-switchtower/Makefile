# New ports collection makefile for:	rubygem-switchtower
# Date created:				14 January 2006
# Whom:					Roderick van Domburg <r.s.a.vandomburg@student.utwente.nl>
#
# $FreeBSD$
#

PORTNAME=	switchtower
PORTVERSION=	1.0.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	http://rubyforge.org/frs/download.php/8664/

MAINTAINER=	r.s.a.vandomburg@student.utwente.nl
COMMENT=	A utility for executing commands in parallel on multiple machines

RUN_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/net-sftp-1.1.0.gemspec:${PORTSDIR}/security/rubygem-net-sftp

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
