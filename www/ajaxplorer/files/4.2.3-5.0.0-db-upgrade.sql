/* SEPARATOR */
ALTER TABLE `ajxp_user_rights` CHANGE `rights` `rights` MEDIUMTEXT NOT NULL;
/* SEPARATOR */
ALTER TABLE `ajxp_users` ADD COLUMN `groupPath` VARCHAR(255) NULL;
/* SEPARATOR */
ALTER TABLE `ajxp_repo` ADD COLUMN `groupPath` VARCHAR(255) NULL;
/* SEPARATOR */
ALTER TABLE `ajxp_repo_options` ADD INDEX (uuid);
/* SEPARATOR */
CREATE TABLE IF NOT EXISTS ajxp_groups (
    groupPath VARCHAR(255) PRIMARY KEY,
    groupLabel VARCHAR(255) NOT NULL
);
/* SEPARATOR */
CREATE TABLE IF NOT EXISTS ajxp_simple_store (
   object_id VARCHAR(255) NOT NULL,
   store_id VARCHAR(50) NOT NULL,
   serialized_data LONGTEXT NULL,
   binary_data LONGBLOB NULL,
   related_object_id VARCHAR(255) NULL,
   PRIMARY KEY(object_id, store_id)
);
