# New ports collection makefile for:	bsnmpd
# Date created:				Sep 22 2005
# Whom:					Andrey V. Elsukov <bu7cher@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	bsnmpd
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://people.freebsd.org/~harti/bsnmp/
DISTNAME=	bsnmp-${PORTVERSION}a

MAINTAINER=	bu7cher@yandex.ru
COMMENT=	A mini-SNMP daemon

LIB_DEPENDS=	begemot.1:${PORTSDIR}/devel/libbegemot \
		smi.2:${PORTSDIR}/net-mgmt/libsmi

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libbegemot=${LOCALBASE}

USE_AUTOTOOLS=	automake:19 autoconf:259
INSTALLS_SHLIB=		yes

USE_GCC=	3.2+
USE_RC_SUBR=	bsnmpd.sh

MAN1=	bsnmpd.1 gensnmptree.1 gensnmpdef.1
MAN3=	asn1.3 bsnmplib.3 bsnmpclient.3 bsnmpagent.3 snmpmod.3 \
	snmp_mibII.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 600000
IGNORE=	bsnmpd already in base system
.endif

run-autotools:
	@(cd ${CONFIGURE_WRKSRC} && ${LOCALBASE}/bin/aclocal19 )
	@(cd ${CONFIGURE_WRKSRC} && ${LOCALBASE}/bin/autoconf259 )

post-install:
	@${MKDIR} ${PREFIX}/etc
	@${INSTALL_DATA} ${BUILD_WRKSRC}/snmpd/snmpd.config ${PREFIX}/etc/snmpd.config.example

.include <bsd.port.post.mk>
