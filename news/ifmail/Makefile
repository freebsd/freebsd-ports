# $FreeBSD$

PORTNAME=	ifmail
PORTVERSION=	2.15
PORTREVISION=	5
CATEGORIES=	news comms
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/fido

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	FidoNet(tm) support package for UN*X platform

NEED_ROOT=	yes

MAN3=		parsedate.3
MAN8=		ifmail.8 iftoss.8
IFMAIL_RUNAS?=	ifmail
PLIST_SUB+=	IFMAIL_RUNAS="${IFMAIL_RUNAS}"
# USERS does not work here
#USERS=		ifmail

.include <bsd.port.options.mk>

pre-configure:
	${REINPLACE_CMD} -e 's|OWNER = ifmail|OWNER = ${IFMAIL_RUNAS}|' \
		-e 's|CC = gcc|CC = ${CC}|' \
		-e 's|-O2 -Wall|${CFLAGS} -DHAS_STDARG_H -Wall|' \
		${WRKSRC}/CONFIG

pre-install:
	if ! pw usershow ${IFMAIL_RUNAS}; then pw useradd ${IFMAIL_RUNAS} -g uucp -u 75 \
		-h - -d /nonexistent -s /nonexistent -c "Ifmail Server"; fi
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/ifmail

post-install:
.for i in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/ifgate/${i} ${STAGEDIR}${PREFIX}/man/man8/
.endfor
.for i in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/iflib/${i} ${STAGEDIR}${PREFIX}/man/man3/
.endfor
	@${ECHO_CMD} "updating ${ROOTDIR}/etc/services"
	@${CP} ${ROOTDIR}/etc/services ${ROOTDIR}/etc/services.bak
	@(grep -v ^ifcico ${ROOTDIR}/etc/services.bak; \
	${ECHO_CMD} "ifcico		60179/tcp  #ifcico server (ifmail)") \
		> ${ROOTDIR}/etc/services
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/
.for i in ifcico ifgate iflib
	${INSTALL_DATA} ${WRKSRC}/${i}/README ${STAGEDIR}${DOCSDIR}/README.${i}
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC}/misc -cf - . | ${TAR} -C ${STAGEDIR}${EXAMPLESDIR} -xf -
.endif

.include <bsd.port.mk>
