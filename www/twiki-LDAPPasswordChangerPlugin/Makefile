# Created by: Alexey V. Degtyarev
# $FreeBSD$

PORTNAME=	LDAPPasswordChangerPlugin
PORTVERSION=	0.0.${SVNREV}
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Change TWiki password at a pre-configured LDAP server

RUN_DEPENDS=	p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap

SVNREV=		18108

NO_STAGE=	yes
.include "${.CURDIR}/../twiki/bsd.twiki.mk"
.include <bsd.port.mk>
