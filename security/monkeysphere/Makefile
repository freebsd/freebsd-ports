# Created by: Daniel Kahn Gillmor <dkg@fifthhorseman.net>
# $FreeBSD$

PORTNAME=	monkeysphere
PORTVERSION=	0.24
CATEGORIES=	security
MASTER_SITES=	http://archive.monkeysphere.info/debian/pool/monkeysphere/m/monkeysphere/
# hack for debian orig tarballs
DISTFILES=	${PORTNAME}_${DISTVERSION}.orig.tar.gz

MAINTAINER=	dkg@fifthhorseman.net
COMMENT=	Use the OpenPGP web of trust to verify ssh connections

RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg1 \
		lockfile:${PORTSDIR}/mail/procmail \
		bash:${PORTSDIR}/shells/bash \
		p5-Crypt-OpenSSL-RSA>=0:${PORTSDIR}/security/p5-Crypt-OpenSSL-RSA \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1

MAN1=		monkeysphere.1 openpgp2ssh.1 pem2openpgp.1
MAN7=		monkeysphere.7
MAN8=		monkeysphere-host.8 monkeysphere-authentication.8
MANCOMPRESSED=	yes

USERS=	monkeysphere
GROUPS=	monkeysphere

MAKE_ARGS=	ETCPREFIX=${PREFIX} MANPREFIX=${PREFIX}/man ETCSUFFIX=.sample

NO_STAGE=	yes
# use proper system paths for FreeBSD instead of debian's:
post-patch:
	@${REINPLACE_CMD} -e 's|/etc/monkeysphere|/usr/local/etc/monkeysphere|g' \
	  ${WRKSRC}/src/share/defaultenv \
	  ${WRKSRC}/src/transitions/0.23 \
	  ${WRKSRC}/man/man1/monkeysphere.1 \
	  ${WRKSRC}/man/man8/monkeysphere-authentication.8 \
	  ${WRKSRC}/man/man8/monkeysphere-host.8 \
	  ${WRKSRC}/etc/monkeysphere-authentication.conf
	@${REINPLACE_CMD} -e 's|/var/lib/monkeysphere|/var/monkeysphere|g' \
	  ${WRKSRC}/src/transitions/0.23 \
	  ${WRKSRC}/man/man1/monkeysphere.1 \
	  ${WRKSRC}/man/man8/monkeysphere-authentication.8 \
	  ${WRKSRC}/man/man8/monkeysphere-host.8 \
	  ${WRKSRC}/src/monkeysphere-host \
	  ${WRKSRC}/src/monkeysphere-authentication \
	  ${WRKSRC}/doc/getting-started-admin.mdwn
	@${REINPLACE_CMD} -e 's|/usr/share/monkeysphere|/usr/local/share/monkeysphere|g' \
	  ${WRKSRC}/src/monkeysphere-host \
	  ${WRKSRC}/src/monkeysphere-authentication \
	  ${WRKSRC}/src/monkeysphere
	# and clean up cruft from the sed replacements:
	${FIND} ${WRKSRC} -name '*.bak' -delete

post-install:
	@if [ ! -f ${PREFIX}/etc/monkeysphere/monkeysphere.conf ]; then \
		${CP} -p ${PREFIX}/etc/monkeysphere/monkeysphere.conf.sample ${PREFIX}/etc/monkeysphere/monkeysphere.conf ; \
	fi
	@if [ ! -f ${PREFIX}/etc/monkeysphere/monkeysphere-host.conf ]; then \
		${CP} -p ${PREFIX}/etc/monkeysphere/monkeysphere-host.conf.sample ${PREFIX}/etc/monkeysphere/monkeysphere-host.conf ; \
	fi
	@if [ ! -f ${PREFIX}/etc/monkeysphere/monkeysphere-authentication.conf ]; then \
		${CP} -p ${PREFIX}/etc/monkeysphere/monkeysphere-authentication.conf.sample ${PREFIX}/etc/monkeysphere/monkeysphere-authentication.conf ; \
	fi
.if !defined(PACKAGE_BUILDING)
	@${SETENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
