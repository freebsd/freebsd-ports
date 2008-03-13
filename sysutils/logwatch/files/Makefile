# $FreeBSD$

PORTNAME?=logwatch
PREFIX?=/usr/local/${PORTNAME}
ETCDIR?=${PREFIX}/etc/${PORTNAME}
LIBDIR?=${PREFIX}/lib/${PORTNAME}
LIBEXECDIR?=${PREFIX}/libexec/${PORTNAME}
CACHEDIR?=${PREFIX}/var/${PORTNAME}
MANDIR?=${PREFIX}/man
MAN8DIR?=${MANDIR}/man8
PERL_VER?=5.8.8
SITE_PERL_REL?=	lib/perl5/site_perl/${PERL_VER}
SITE_PERL?=	${PREFIX}/${SITE_PERL_REL}

all: logwatch

logwatch:
	@echo "There is no build target, only install."
	@echo "If you are not using FreeBSD ports,"
	@echo "please run, ./install_logwatch.sh after"
	@echo "reading the ./README file."

install:
	install -d ${PREFIX}/sbin
	install -d ${ETCDIR}/html
	install -d ${ETCDIR}/logfiles
	install -d ${ETCDIR}/services
	install -d ${ETCDIR}/defaults/html
	install -d ${ETCDIR}/defaults/logfiles
	install -d ${ETCDIR}/defaults/services
	install -d ${LIBEXECDIR}
	install -d ${SITE_PERL}
	install -d ${CACHEDIR}
	install -d ${MAN8DIR}
	install -m 555 scripts/logwatch.pl ${PREFIX}/sbin
	install -m 555 lib/Logwatch.pm ${SITE_PERL}
	install -m 444 logwatch.8 ${MAN8DIR}
	install -m 644 conf/logwatch.conf ${ETCDIR}/defaults
	install -m 640 conf/ignore.conf ${ETCDIR}/defaults
	install -m 444 conf/html/header.html ${ETCDIR}/defaults/html
	install -m 444 conf/html/footer.html ${ETCDIR}/defaults/html
.for etcdir in html logfiles services
	mkdir -p ${ETCDIR}/defaults/${etcdir}
.endfor
.for scriptdir in logfiles services shared
	mkdir -p ${LIBEXECDIR}/defaults/${scriptdir}
.endfor
.for logfile in \
	autorpm \
	bfd \
	cisco \
	clam-update \
	cron \
	daemon \
	denyhosts \
	dnssec \
	dpkg \
	emerge \
	eventlog \
	exim \
	extreme-networks \
	fail2ban \
	http \
	iptables \
	kernel \
	maillog \
	messages \
	netopia \
	netscreen \
	php \
	pix \
	pureftp \
	qmail-pop3d-current \
	qmail-pop3ds-current \
	qmail-send-current \
	qmail-smtpd-current \
	resolver \
	rt314 \
	samba \
	secure \
	sonicwall \
	syslog \
	tac_acc \
	up2date \
	vsftpd \
	windows \
	xferlog \
	yum 
	install -m 640 conf/logfiles/${logfile}.conf ${ETCDIR}/defaults/logfiles/${logfile}.conf
.endfor
.for service in \
	afpd \
	amavis \
	arpwatch \
	audit \
	automount \
	autorpm \
	bfd \
	cisco \
	clam-update \
	clamav \
	clamav-milter \
	courier \
	cron \
	denyhosts \
	dhcpd \
	dnssec \
	dovecot \
	dpkg \
	emerge \
	evtapplication \
	evtsecurity \
	evtsystem \
	exim \
	eximstats \
	extreme-networks \
	fail2ban \
	ftpd-messages \
	ftpd-xferlog \
	http \
	identd \
	imapd \
	in.qpopper \
	init \
	ipop3d \
	iptables \
	kernel \
	mailscanner \
	modprobe \
	mountd \
	named \
	netopia \
	netscreen \
	oidentd \
	openvpn \
	pam \
	pam_pwdb \
	pam_unix \
	php \
	pix \
	pluto \
	pop3 \
	portsentry \
	postfix \
	pound \
	proftpd-messages \
	pureftpd \
	qmail \
	qmail-pop3d \
	qmail-pop3ds \
	qmail-send \
	qmail-smtpd \
	raid \
	resolver \
	rt314 \
	samba \
	saslauthd \
	scsi \
	secure \
	sendmail \
	sendmail-largeboxes \
	shaperd \
	slon \
	smartd \
	sonicwall \
	sshd \
	sshd2 \
	stunnel \
	sudo \
	syslogd \
	tac_acc \
	up2date \
	vpopmail \
	vsftpd \
	windows \
	xntpd \
	yum \
	zz-disk_space \
	zz-fortune \
	zz-network \
	zz-runtime \
	zz-sys 
	install -m 444 scripts/services/${service} ${LIBEXECDIR}/defaults/services/${service}
	install -m 444 conf/services/${service}.conf ${ETCDIR}/defaults/services/${service}.conf
.endfor
.for script in \
	applybinddate \
	applyeurodate \
	applyhttpdate \
	applystddate \
	applytaidate \
	applyusdate \
	eventlogonlyservice \
	eventlogremoveservice \
	expandrepeats \
	hosthash \
	hostlist \
	multiservice \
	onlycontains \
	onlyhost \
	onlyservice \
	remove \
	removeheaders \
	removeservice 
	install -m 555 scripts/shared/${script} ${LIBEXECDIR}/defaults/shared/${script}
.endfor
.for logfile in autorpm cron emerge samba up2date xferlog yum
	mkdir -p ${LIBEXECDIR}/defaults/logfiles/${logfile}
	install -m 555 scripts/logfiles/${logfile}/applydate ${LIBEXECDIR}/defaults/logfiles/${logfile}
.endfor
.for logfile in samba up2date xferlog 
	install -m 555 scripts/logfiles/${logfile}/removeheaders ${LIBEXECDIR}/defaults/logfiles/${logfile}
.endfor
