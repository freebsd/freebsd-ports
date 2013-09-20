# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cpu
PORTVERSION=	1.4.3
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Change Password Utility for LDAP

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_OPENLDAP=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/cpu --with-ldap=${LOCALBASE}
CPPFLAGS+=	-DLDAP_DEPRECATED

MAN5=		cpu.conf.5
MAN8=		cpu.8 cpu-ldap.8

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
