CREATE TABLE `vhosts_secure`(
	vhost_secure_id bigint(20) NOT NULL AUTO_INCREMENT,
	vhost_secure_username varchar(255) NOT NULL,
	vhost_secure_password varchar(255) NOT NULL,
	vhost_secure_realm varchar(255) NOT NULL
	PRIMARY KEY (vhost_secure_id),
	INDEX i_username (vhost_secure_username),
	INDEX i_password (vhost_secure_password),
	INDEX i_realm (vhost_secure_realm)
);
