# New ports collection makefile for:    sudo
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	sudo
PORTVERSION=	1.6.3.7
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cs.colorado.edu/pub/sysadmin/sudo/ \
		ftp://ftp.stikman.com/pub/sudo/ \
		ftp://ftp.uu.net/pub/security/sudo/
DISTNAME=	${PORTNAME}-1.6.3p7

MAINTAINER=	mharo@FreeBSD.org

GNU_CONFIGURE=	yes

CONFIGURE_ARGS= --sysconfdir=${PREFIX}/etc \
		--disable-log-wrap \
		--with-ignore-dot \
		--with-tty-tickets \
		--with-env-editor \
		--with-insults \
		--with-all-insults \
		--with-logincap \
		--disable-root-sudo \
		--with-long-otp-prompt \
		--with-pam

.include <bsd.port.pre.mk>

.if defined(WITH_OPIE) || ${OSVERSION} > 500021
CONFIGURE_ARGS+=--with-opie
.else
CONFIGURE_ARGS+=--with-skey
.endif

MAN5=		sudoers.5
MAN8=		sudo.8 visudo.8

post-patch:
	perl -i -pe 's,^,#,g' ${WRKSRC}/sample.sudoers

post-install:
	${INSTALL_DATA} ${WRKSRC}/sample.sudoers ${PREFIX}/etc/sudoers.sample

.include <bsd.port.post.mk>
