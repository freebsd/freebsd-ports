# Created by: Raffaele De Lorenzo  - raffaele.delorenzo@libero.it
# $FreeBSD$

PORTNAME=	ss5
PORTVERSION=	3.8.5
CATEGORIES=	net security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}-1
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	raffaele.delorenzo@libero.it
COMMENT=	SOCKS v4/v5 application layer gateway with many features

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_OPENLDAP=	yes
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-binpathbase=${PREFIX}/sbin \
		--with-docpathbase=${PREFIX}/share/doc \
		--with-confpathbase=${PREFIX}/etc \
		--with-libpath=${PREFIX}/lib

MAKE_ENV=	DATADIR=${DATADIR} EXAMPLESDIR=${EXAMPLESDIR}
CFLAGS+=	-DLDAP_DEPRECATED

MAN1=		ss5.1 ss5srv.1
MAN5=		ss5.conf.5 ss5.pam.5 ss5.passwd.5 ss5.ha.5 ss5_gss.5 ss5_supa.5
MANCOMPRESSED=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's,/usr/local/etc/opt/ss5,${PREFIX}/etc/ss5,' \
		${WRKSRC}/include/config.h.in

post-install:
#	${TOUCH} ${PREFIX}/etc/ss5/ss5.ha.default
#.if !exists(${PREFIX}/etc/ss5/ss5.ha)
#	${TOUCH} ${PREFIX}/etc/ss5/ss5.ha
#.endif
	${INSTALL_DATA} ${WRKSRC}/conf/examples/ss5.ha ${PREFIX}/etc/${PORTNAME}/ss5.ha.default
	if [ ! -f ${PREFIX}/etc/${PORTNAME}.ha ]; then \
		${INSTALL_DATA} ${WRKSRC}/conf/examples/ss5.ha ${PREFIX}/etc/${PORTNAME}/ss5.ha ; \
	fi

.include <bsd.port.mk>
