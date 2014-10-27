# Created by: Raffaele De Lorenzo  - raffaele.delorenzo@libero.it
# $FreeBSD$

PORTNAME=	ss5
PORTVERSION=	3.8.5
PORTREVISION=	2
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
MAKE_ARGS+=	CC="${CC}"
CFLAGS+=	-DLDAP_DEPRECATED

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's,/usr/local/etc/opt/ss5,${PREFIX}/etc/ss5,' \
		${WRKSRC}/include/config.h.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/ss5.conf \
		${STAGEDIR}${PREFIX}/etc/ss5/ss5.conf.sample
	${INSTALL_DATA} ${WRKSRC}/conf/ss5.ha \
		${STAGEDIR}${PREFIX}/etc/ss5/ss5.ha.sample
	${INSTALL_DATA} ${WRKSRC}/conf/ss5.passwd \
		${STAGEDIR}${PREFIX}/etc/ss5/ss5.passwd.sample

.include <bsd.port.mk>
