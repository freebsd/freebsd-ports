# New ports collection makefile for:	p5-IC-Radius
# Date created:				04 Jul 2001
# Whom:	      				Sergey N. Voronkov <serg@tmn.ru>
#
# $FreeBSD$
#

PORTNAME=	icradius
PORTVERSION=	0.18.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.innercite.com/pub/icradius/

FORBIDDEN=	"Remotely exploitable buffer overflow. See ports/net/freeradius for compatible and non-exploitable replacement."

MAINTAINER=	ports@FreeBSD.org

MAKEFILE=	Makefile.BSD

.if defined(WITH_CGI)
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IC/Radius.pm:${PORTSDIR}/net/p5-IC-Radius \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MD5.pm:${PORTSDIR}/security/p5-MD5
.endif
LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

MAN8=		radiusd.8

IC_LIB=		${PREFIX}/share/icradius
.if !defined(NOPORTDOCS)
IC_DOC=		${PREFIX}/share/doc/icradius
.endif

.if defined(WITH_CGI)
PLIST_SUB+=	CGI=""
.else
PLIST_SUB+=	CGI="@comment "
.endif

# Define FOR_CISCO=yes to make it CISCO specific

.if defined(FOR_CISCO)
post-patch:
	( cd ${WRKSRC} ; \
	for fn in ${FILESDIR}/pcisco-*; do \
		${PATCH} < $$fn; \
	done )
.endif

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE}

do-install:
	[ -d /var/log/radacct ] || ${MKDIR} -m 700 /var/log/radacct
	@${MKDIR} ${PREFIX}/etc/raddb
	${INSTALL_DATA} -m 600 ${WRKSRC}/raddb/radius.conf \
		${PREFIX}/etc/raddb/radius.conf.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${IC_DOC}
	${INSTALL_DATA} ${WRKSRC}/COPY* ${IC_DOC}
	${INSTALL_DATA} ${WRKSRC}/doc/README* ${IC_DOC}
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ ${IC_DOC}
	${INSTALL_DATA} ${WRKSRC}/doc/THANKS ${IC_DOC}
	${INSTALL_DATA} ${WRKSRC}/doc/TODO ${IC_DOC}
.endif
	@${MKDIR} ${IC_LIB}
	@${MKDIR} ${IC_LIB}/raddb
	for fn in dictionary dictionary.ascend dictionary.cisco \
		dictionary.compat dictionary.foundry dictionary.livingston \
		dictionary.merit dictionary.redback dictionary.shiva \
		dictionary.tunnel dictionary.usr dictionary.versanet \
		huntgroups; do \
		${INSTALL_DATA} ${WRKSRC}/raddb/$$fn ${IC_LIB}/raddb; \
	done
	@${MKDIR} ${IC_LIB}/scripts
	cd ${WRKSRC}/scripts && ${CP} -rp *.pl radius.db images \
		radlast radwho README ${IC_LIB}/scripts
	${INSTALL_PROGRAM} ${WRKSRC}/src/radiusd ${PREFIX}/sbin
	${SED} "s#%%PREFIX%%#${PREFIX}#" ${WRKSRC}/src/checkrad.pl > ${PREFIX}/sbin/checkrad
	${CHMOD} 711 ${PREFIX}/sbin/checkrad
	${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/sbin/checkrad
	${SED} "s#%%PREFIX%%#${PREFIX}#" ${WRKSRC}/scripts/radwatch > ${PREFIX}/sbin/radwatch
	${CHMOD} 755 ${PREFIX}/sbin/radwatch
	${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/sbin/radwatch
	${INSTALL_MAN} ${WRKSRC}/doc/radiusd.8 ${MANPREFIX}/man/man8
.if defined(WITH_CGI)
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/radius.cgi ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/usage.cgi ${PREFIX}/libexec
.endif
	${INSTALL_SCRIPT} ${FILESDIR}/icradiusd.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
