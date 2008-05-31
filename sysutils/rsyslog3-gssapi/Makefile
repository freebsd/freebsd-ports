# New ports collection makefile for:	rsyslog3-gssapi
# Date created:		31 December 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

COMMENT=	GSS API input/output module for rsyslog

MNAME=	gssapi
MTYPES=	im om

.include "${.CURDIR}/../rsyslog3/bsd.rsyslog.mk"
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile
.endif

.include <bsd.port.post.mk>
