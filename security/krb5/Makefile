# Ports collection Makefile for:	MIT Kerberos V
# Date created:				6/5/1998
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		krb5
PORTVERSION=		1.8.1
CATEGORIES=		security
MASTER_SITES=		http://web.mit.edu/kerberos/dist/${PORTNAME}/${PORTVERSION:C/^[0-9]*\.[0-9]*/&X/:C/X\.[0-9]*$//:C/X//}/
PATCH_SITES=		http://web.mit.edu/kerberos/advisories/
DISTNAME=		${PORTNAME}-${PORTVERSION}-signed
EXTRACT_SUFX=		.tar

MAINTAINER=		cy@FreeBSD.org
COMMENT=		An authentication system developed at MIT, successor to Kerberos IV

BUILD_DEPENDS=		gm4:${PORTSDIR}/devel/m4

CONFLICTS=		krb[45]-[0-9]* heimdal-[0-9]* srp-[0-9]*

LATEST_LINK=		${PORTNAME}-18
KERBEROSV_URL=		http://web.mit.edu/kerberos/
USE_OPENSSL=		yes
WITH_OPENSSL_PORT=	yes
USE_GMAKE=		yes
USE_PERL5_BUILD=	yes
USE_LDCONFIG=		yes
USE_AUTOTOOLS=		libtool:22
CONFIGURE_ARGS?=	--enable-shared
CONFIGURE_ENV=		INSTALL="${INSTALL}" YACC=/usr/bin/yacc \
			CFLAGS="${CFLAGS}"
MAKE_ARGS=		INSTALL="${INSTALL}"

OPTIONS=		KRB5_DOC "Build and install krb5 documentation" on \
			WANT_HTML "Want HTML documentation too" on \
			DNS_FOR_REALM "enable DNS lookups of Kerberos realm names" off

.include <bsd.port.pre.mk>

.if defined(WITH_DNS_FOR_REALM)
CONFIGURE_ARGS+=	--enable-dns-for-realm
.endif

.if defined(WITH_KRB5_DOC)
BUILD_DEPENDS+=		texi2dvi:${PORTSDIR}/print/texinfo \
			dvips:${PORTSDIR}/print/dvipsk-tetex
INFO=			krb5-admin krb5-install krb5-user
.endif

.if defined(KRB5_HOME)
PREFIX=			${KRB5_HOME}
.endif

MAN1=			k5srvutil.1 kadmin.1 krb5-send-pr.1 krb5-config.1 \
			kpasswd.1 klist.1 kinit.1 kdestroy.1 ksu.1 ktutil.1 \
			sclient.1 kerberos.1 kvno.1 compile_et.1
MAN5=			kdc.conf.5 krb5.conf.5 .k5login.5
MAN8=			krb5kdc.8 kadmin.local.8 kdb5_util.8 kadmind.8 \
			kprop.8 kpropd.8 kproplog.8 sserver.8

.if defined(PROGRAM_TRANSFORM_NAME) && ${PROGRAM_TRANSFORM_NAME} != ""
CONFIGURE_ARGS+=	--program-transform-name="${PROGRAM_TRANSFORM_NAME}"
.endif

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

HTML_DOC_DIR=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/doc
HTML_DOCS=		ftp.html kdestroy.html kinit.html klist.html \
			kpasswd.html krb5-admin.html \
			krb5-install.html krb5-user.html ksu.html \
			rcp.html rlogin.html rsh.html telnet.html

CONFIGURE_ARGS+=	CPPFLAGS="-I${OPENSSLINC} -L${OPENSSLLIB}"

post-extract:
	@${TAR} -C ${WRKDIR} -xzf ${WRKDIR}/${PORTNAME}-${PORTVERSION}.tar.gz
	@${RM} ${WRKDIR}/${PORTNAME}-${PORTVERSION}.tar.gz ${WRKDIR}/${PORTNAME}-${PORTVERSION}.tar.gz.asc
.if !defined(EXTRACT_PRESERVE_OWNERSHIP)
	@if [ `id -u` = 0 ]; then \
		${CHMOD} -R ug-s,go-w ${WRKDIR}/${PORTNAME}-${PORTVERSION}; \
		${CHOWN} -R 0:0 ${WRKDIR}/${PORTNAME}-${PORTVERSION}; \
	fi
.endif

post-patch:
	@${REINPLACE_CMD} -e '1s,^#!\/usr\/athena/bin/perl,#!${PERL5},' \
		${WRKSRC}/../doc/man2html

post-build:
.if defined(WITH_KRB5_DOC)
	@cd ${WRKSRC}/../doc && \
	${MAKE} all
.endif

post-install:
	@${MKDIR} ${PREFIX}/share/doc/krb5
# html documentation
.if defined(WITH_KRB5_DOC) && defined(WITH_WANT_HTML)
	for html in ${HTML_DOC_DIR}/*.html; do \
		${INSTALL_MAN} $${html} ${PREFIX}/share/doc/krb5; \
		${ECHO_CMD} share/doc/krb5/`${BASENAME} $${html}` >> ${TMPPLIST}; \
	done
.endif
	${ECHO_CMD} @dirrm share/doc/krb5 >> ${TMPPLIST}
# handle info files
.if defined(WITH_KRB5_DOC)
.for info in ${INFO}
	${INSTALL_MAN} ${WRKSRC}/../doc/${info}.info ${PREFIX}/info/${info}.info
.endfor
.endif

	@${SED} "s%\${PREFIX}%${PREFIX}%" ${FILESDIR}/README.FreeBSD > ${PREFIX}/share/doc/krb5/README.FreeBSD
	@${CHMOD} 444 ${PREFIX}/share/doc/krb5/README.FreeBSD
	@${ECHO} "------------------------------------------------------"
	@${ECHO} "This port of MIT Kerberos 5 includes remote login     "
	@${ECHO} "daemons (telnetd and klogind).  These daemons default "
	@${ECHO} "to using the system login program (/usr/bin/login).   "
	@${ECHO} "Please see the file                                   "
	@${ECHO} "${PREFIX}/share/doc/krb5/README.FreeBSD"
	@${ECHO} "for more information.                                 "
	@${ECHO} "------------------------------------------------------"

.include <bsd.port.post.mk>
