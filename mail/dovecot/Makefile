# New ports collection makefile for:	dovecot
# Date created:				12/08/2002
# Whom:			Dominic Marks <d.marks@student.umist.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	dovecot
PORTVERSION=	0.98.4
CATEGORIES=	mail ipv6
MASTER_SITES=	http://dovecot.procontrol.fi/

MAINTAINER=	d.marks@student.umist.ac.uk

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-shadow --enable-ipv6 \
		--localstatedir=/var/dovecot

pre-build:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/dovecot-example.conf

pre-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${MKDIR} /var/dovecot
	@${MKDIR} /var/dovecot/auth
	@${MKDIR} /var/dovecot/login
	@${CHOWN} imapd:imapd /var/dovecot
	@if [ ! -f ${PREFIX}/etc/rc.d/dovecot-imapd.sh ]; then \
		${ECHO} "Installing dovecot-imapd.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/dovecot-imapd.sh \
			${PREFIX}/etc/rc.d/dovecot-imapd.sh; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/dovecot
	@${INSTALL_DATA} \
		${WRKSRC}/doc/auth.txt \
		${WRKSRC}/doc/design.txt \
		${WRKSRC}/doc/index.txt \
		${WRKSRC}/doc/multiaccess.txt \
		${WRKSRC}/doc/nfs.txt \
		${PREFIX}/share/doc/dovecot
.endif

.include <bsd.port.mk>
