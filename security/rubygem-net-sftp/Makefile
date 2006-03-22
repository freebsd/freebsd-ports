# New ports collection makefile for:	rubygem-net-sftp
# Date created:				14 January 2006
# Whom:					Roderick van Domburg <r.s.a.vandomburg@student.utwente.nl>
#
# $FreeBSD$
#

PORTNAME=	net-sftp
PORTVERSION=	1.1.0
CATEGORIES=	security rubygems
MASTER_SITES=	http://rubyforge.org/frs/download.php/7928/

MAINTAINER=	r.s.a.vandomburg@student.utwente.nl
COMMENT=	Implementation of the SFTP client protocol

RUN_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/net-ssh-1.0.8.gemspec:${PORTSDIR}/security/rubygem-net-ssh

post-install:
	@${ECHO_MSG} "You may safely ignore any 'Skipping require of dynamic string' messages."

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
